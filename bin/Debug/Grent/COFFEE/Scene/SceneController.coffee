
BaseController = require("./../../base/BaseController.coffee")
SceneModel = require("./SceneModel.coffee")



SceneController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetNewPlayerNotifyCB(@NewPlayerCBNotify)
        _model.SetDeletePlayerNotifyCB(@DeletePlayerCBNotify)

        return



    NewPlayerCBNotify:(ret_msg)->
        cc.log "NewPlayerCBNotify Respond "
    DeletePlayerCBNotify:(ret_msg)->
        cc.log "DeletePlayerCBNotify Respond "


)
SceneController.getInstance = ->
    if this.instance is undefined
        model_ = SceneModel
        model_.Initialize()
        this.instance = new SceneController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = SceneController.getInstance()
    controller_)()
  
