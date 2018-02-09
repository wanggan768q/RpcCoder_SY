
BaseController = require("./../../base/BaseController.coffee")
EventModel = require("./EventModel.coffee")



EventController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetMoveNotifyCB(@MoveCBNotify)
        _model.SetStopMoveNotifyCB(@StopMoveCBNotify)
        _model.SetObjAttrChangeNotifyCB(@ObjAttrChangeCBNotify)

        return



    MoveCBNotify:(ret_msg)->
        cc.log "MoveCBNotify Respond "
    StopMoveCBNotify:(ret_msg)->
        cc.log "StopMoveCBNotify Respond "
    ObjAttrChangeCBNotify:(ret_msg)->
        cc.log "ObjAttrChangeCBNotify Respond "


)
EventController.getInstance = ->
    if this.instance is undefined
        model_ = EventModel
        model_.Initialize()
        this.instance = new EventController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = EventController.getInstance()
    controller_)()
  
