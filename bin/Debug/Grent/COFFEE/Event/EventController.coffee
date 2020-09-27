
BaseController = require("./../../base/BaseController.coffee")
EventModel = require("./EventModel.coffee")



EventController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetMoveNotifyCB(@MoveCBNotify)
        _model.SetStopMoveNotifyCB(@StopMoveCBNotify)
        _model.SetObjAttrChangeNotifyCB(@ObjAttrChangeCBNotify)
        _model.SetCoinChangeNotifyCB(@CoinChangeCBNotify)
        _model.SetMovePosNotifyCB(@MovePosCBNotify)
        _model.SetDirNotifyCB(@DirCBNotify)
        _model.SetStartFadeoutNotifyCB(@StartFadeoutCBNotify)
        _model.SetCinematicStartNotifyCB(@CinematicStartCBNotify)
        _model.SetCinematicEndNotifyCB(@CinematicEndCBNotify)

        return



    MoveCBNotify:(ret_msg)->
        cc.log "MoveCBNotify Respond "
    StopMoveCBNotify:(ret_msg)->
        cc.log "StopMoveCBNotify Respond "
    ObjAttrChangeCBNotify:(ret_msg)->
        cc.log "ObjAttrChangeCBNotify Respond "
    CoinChangeCBNotify:(ret_msg)->
        cc.log "CoinChangeCBNotify Respond "
    MovePosCBNotify:(ret_msg)->
        cc.log "MovePosCBNotify Respond "
    DirCBNotify:(ret_msg)->
        cc.log "DirCBNotify Respond "
    StartFadeoutCBNotify:(ret_msg)->
        cc.log "StartFadeoutCBNotify Respond "
    CinematicStartCBNotify:(ret_msg)->
        cc.log "CinematicStartCBNotify Respond "
    CinematicEndCBNotify:(ret_msg)->
        cc.log "CinematicEndCBNotify Respond "


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
  
