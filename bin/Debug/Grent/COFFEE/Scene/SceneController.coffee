
BaseController = require("./../../base/BaseController.coffee")
SceneModel = require("./SceneModel.coffee")



SceneController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetDeletePlayerNotifyCB(@DeletePlayerCBNotify)
        _model.SetCreateObjNotifyCB(@CreateObjCBNotify)
        _model.SetCEnterSceneNotifyCB(@CEnterSceneCBNotify)
        _model.SetSEnterSceneNotifyCB(@SEnterSceneCBNotify)
        _model.SetObjDieNotifyCB(@ObjDieCBNotify)

        return



    DeletePlayerCBNotify:(ret_msg)->
        cc.log "DeletePlayerCBNotify Respond "
    CreateObjCBNotify:(ret_msg)->
        cc.log "CreateObjCBNotify Respond "
    CEnterSceneCBNotify:(ret_msg)->
        cc.log "CEnterSceneCBNotify Respond "
    SEnterSceneCBNotify:(ret_msg)->
        cc.log "SEnterSceneCBNotify Respond "
    ObjDieCBNotify:(ret_msg)->
        cc.log "ObjDieCBNotify Respond "


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
  
