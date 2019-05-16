
BaseController = require("./../../base/BaseController.coffee")
FightModel = require("./FightModel.coffee")



FightController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetUseSkillActionNotifyCB(@UseSkillActionCBNotify)
        _model.SetShowExpActionNotifyCB(@ShowExpActionCBNotify)
        _model.SetBuffActionNotifyCB(@BuffActionCBNotify)
        _model.SetStateActionNotifyCB(@StateActionCBNotify)
        _model.SetReviveActionNotifyCB(@ReviveActionCBNotify)
        _model.SetComboSkillActionNotifyCB(@ComboSkillActionCBNotify)
        _model.SetDropActionNotifyCB(@DropActionCBNotify)
        _model.SetUseItemActionNotifyCB(@UseItemActionCBNotify)
        _model.SetHpChangeActionNotifyCB(@HpChangeActionCBNotify)
        _model.SetHurtActionNotifyCB(@HurtActionCBNotify)
        _model.SetRepelActionNotifyCB(@RepelActionCBNotify)
        _model.SetObjDeadActionNotifyCB(@ObjDeadActionCBNotify)
        _model.SetFightTipsNotifyCB(@FightTipsCBNotify)
        _model.SetBuffListNotifyCB(@BuffListCBNotify)

        return



    UseSkillActionCBNotify:(ret_msg)->
        cc.log "UseSkillActionCBNotify Respond "
    ShowExpActionCBNotify:(ret_msg)->
        cc.log "ShowExpActionCBNotify Respond "
    BuffActionCBNotify:(ret_msg)->
        cc.log "BuffActionCBNotify Respond "
    StateActionCBNotify:(ret_msg)->
        cc.log "StateActionCBNotify Respond "
    ReviveActionCBNotify:(ret_msg)->
        cc.log "ReviveActionCBNotify Respond "
    ComboSkillActionCBNotify:(ret_msg)->
        cc.log "ComboSkillActionCBNotify Respond "
    DropActionCBNotify:(ret_msg)->
        cc.log "DropActionCBNotify Respond "
    UseItemActionCBNotify:(ret_msg)->
        cc.log "UseItemActionCBNotify Respond "
    HpChangeActionCBNotify:(ret_msg)->
        cc.log "HpChangeActionCBNotify Respond "
    HurtActionCBNotify:(ret_msg)->
        cc.log "HurtActionCBNotify Respond "
    RepelActionCBNotify:(ret_msg)->
        cc.log "RepelActionCBNotify Respond "
    ObjDeadActionCBNotify:(ret_msg)->
        cc.log "ObjDeadActionCBNotify Respond "
    FightTipsCBNotify:(ret_msg)->
        cc.log "FightTipsCBNotify Respond "
    BuffListCBNotify:(ret_msg)->
        cc.log "BuffListCBNotify Respond "


)
FightController.getInstance = ->
    if this.instance is undefined
        model_ = FightModel
        model_.Initialize()
        this.instance = new FightController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = FightController.getInstance()
    controller_)()
  
