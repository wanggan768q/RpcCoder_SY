
BaseController = require("./../../base/BaseController.coffee")
ContactModel = require("./ContactModel.coffee")



ContactController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetAgreeApplicationNotifyNotifyCB(@AgreeApplicationNotifyCBNotify)
        _model.SetNewFriendNotifyCB(@NewFriendCBNotify)
        _model.SetApplyListNotifyCB(@ApplyListCBNotify)
        _model.SetBeRejectApplyNotifyCB(@BeRejectApplyCBNotify)
        _model.SetBeCancelRelationShipNotifyCB(@BeCancelRelationShipCBNotify)
        _model.SetBeAddBlackListNotifyCB(@BeAddBlackListCBNotify)
        _model.SetRoleDataUpdateNotifyCB(@RoleDataUpdateCBNotify)
        _model.SetContactLoginNotifyCB(@ContactLoginCBNotify)
        _model.SetContactLogoutNotifyCB(@ContactLogoutCBNotify)
        _model.SetDeleteRoleDataNotifyCB(@DeleteRoleDataCBNotify)
        _model.SetUnAcquireGiftPointNotifyCB(@UnAcquireGiftPointCBNotify)
        _model.SetAddRoleDataNotifyCB(@AddRoleDataCBNotify)
        _model.SetSetGiftPointNotifyCB(@SetGiftPointCBNotify)
        _model.SetContactsGroupsNotifyCB(@ContactsGroupsCBNotify)
        _model.SetNewChatMsgNotifyCB(@NewChatMsgCBNotify)

        return



    AgreeApplicationNotifyCBNotify:(ret_msg)->
        cc.log "AgreeApplicationNotifyCBNotify Respond "
    NewFriendCBNotify:(ret_msg)->
        cc.log "NewFriendCBNotify Respond "
    ApplyListCBNotify:(ret_msg)->
        cc.log "ApplyListCBNotify Respond "
    BeRejectApplyCBNotify:(ret_msg)->
        cc.log "BeRejectApplyCBNotify Respond "
    BeCancelRelationShipCBNotify:(ret_msg)->
        cc.log "BeCancelRelationShipCBNotify Respond "
    BeAddBlackListCBNotify:(ret_msg)->
        cc.log "BeAddBlackListCBNotify Respond "
    RoleDataUpdateCBNotify:(ret_msg)->
        cc.log "RoleDataUpdateCBNotify Respond "
    ContactLoginCBNotify:(ret_msg)->
        cc.log "ContactLoginCBNotify Respond "
    ContactLogoutCBNotify:(ret_msg)->
        cc.log "ContactLogoutCBNotify Respond "
    DeleteRoleDataCBNotify:(ret_msg)->
        cc.log "DeleteRoleDataCBNotify Respond "
    UnAcquireGiftPointCBNotify:(ret_msg)->
        cc.log "UnAcquireGiftPointCBNotify Respond "
    AddRoleDataCBNotify:(ret_msg)->
        cc.log "AddRoleDataCBNotify Respond "
    SetGiftPointCBNotify:(ret_msg)->
        cc.log "SetGiftPointCBNotify Respond "
    ContactsGroupsCBNotify:(ret_msg)->
        cc.log "ContactsGroupsCBNotify Respond "
    NewChatMsgCBNotify:(ret_msg)->
        cc.log "NewChatMsgCBNotify Respond "


)
ContactController.getInstance = ->
    if this.instance is undefined
        model_ = ContactModel
        model_.Initialize()
        this.instance = new ContactController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = ContactController.getInstance()
    controller_)()
  
