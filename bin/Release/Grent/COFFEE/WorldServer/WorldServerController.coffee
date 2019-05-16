
BaseController = require("./../../base/BaseController.coffee")
WorldServerModel = require("./WorldServerModel.coffee")



WorldServerController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetChangeSceneAskNotifyCB(@ChangeSceneAskCBNotify)
        _model.SetChangeSceneReplyNotifyCB(@ChangeSceneReplyCBNotify)

        return



    ChangeSceneAskCBNotify:(ret_msg)->
        cc.log "ChangeSceneAskCBNotify Respond "
    ChangeSceneReplyCBNotify:(ret_msg)->
        cc.log "ChangeSceneReplyCBNotify Respond "


)
WorldServerController.getInstance = ->
    if this.instance is undefined
        model_ = WorldServerModel
        model_.Initialize()
        this.instance = new WorldServerController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = WorldServerController.getInstance()
    controller_)()
  
