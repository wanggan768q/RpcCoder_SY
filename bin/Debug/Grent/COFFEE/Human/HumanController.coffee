
BaseController = require("./../../base/BaseController.coffee")
HumanModel = require("./HumanModel.coffee")



HumanController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetMoveCheckNotifyCB(@MoveCheckCBNotify)
        _model.SetRespawnOtherNotifyCB(@RespawnOtherCBNotify)
        _model.SetRoleDieNotifyCB(@RoleDieCBNotify)
        _model.SetChangeAnimationStateNotifyCB(@ChangeAnimationStateCBNotify)
        _model.SetClientAttributesNotifyCB(@ClientAttributesCBNotify)
        _model.SetTimeCheckNotifyCB(@TimeCheckCBNotify)
        _model.SetMotionFlagsNotifyCB(@MotionFlagsCBNotify)
        _model.SetChangePositionNotifyCB(@ChangePositionCBNotify)
        _model.SetAttrChangeNotifyCB(@AttrChangeCBNotify)

        return



    MoveCheckCBNotify:(ret_msg)->
        cc.log "MoveCheckCBNotify Respond "
    RespawnOtherCBNotify:(ret_msg)->
        cc.log "RespawnOtherCBNotify Respond "
    RoleDieCBNotify:(ret_msg)->
        cc.log "RoleDieCBNotify Respond "
    ChangeAnimationStateCBNotify:(ret_msg)->
        cc.log "ChangeAnimationStateCBNotify Respond "
    ClientAttributesCBNotify:(ret_msg)->
        cc.log "ClientAttributesCBNotify Respond "
    TimeCheckCBNotify:(ret_msg)->
        cc.log "TimeCheckCBNotify Respond "
    MotionFlagsCBNotify:(ret_msg)->
        cc.log "MotionFlagsCBNotify Respond "
    ChangePositionCBNotify:(ret_msg)->
        cc.log "ChangePositionCBNotify Respond "
    AttrChangeCBNotify:(ret_msg)->
        cc.log "AttrChangeCBNotify Respond "


)
HumanController.getInstance = ->
    if this.instance is undefined
        model_ = HumanModel
        model_.Initialize()
        this.instance = new HumanController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = HumanController.getInstance()
    controller_)()
  
