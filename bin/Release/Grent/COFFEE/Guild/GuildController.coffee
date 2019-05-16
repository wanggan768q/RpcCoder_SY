
BaseController = require("./../../base/BaseController.coffee")
GuildModel = require("./GuildModel.coffee")



GuildController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetKickMemberNotifyNotifyCB(@KickMemberNotifyCBNotify)
        _model.SetVacationNotifyCB(@VacationCBNotify)
        _model.SetReplyVacationNotifyCB(@ReplyVacationCBNotify)
        _model.SetApplyGuildNotifyCB(@ApplyGuildCBNotify)
        _model.SetApplyGuildToOfficeNotifyCB(@ApplyGuildToOfficeCBNotify)
        _model.SetBuildingCanLvUpNotifyCB(@BuildingCanLvUpCBNotify)
        _model.SetOfficeChangeNotifyCB(@OfficeChangeCBNotify)
        _model.SetBuildLvUpCompleteNotifyCB(@BuildLvUpCompleteCBNotify)
        _model.SetGuildCurrencyChangeNotifyCB(@GuildCurrencyChangeCBNotify)

        return



    KickMemberNotifyCBNotify:(ret_msg)->
        cc.log "KickMemberNotifyCBNotify Respond "
    VacationCBNotify:(ret_msg)->
        cc.log "VacationCBNotify Respond "
    ReplyVacationCBNotify:(ret_msg)->
        cc.log "ReplyVacationCBNotify Respond "
    ApplyGuildCBNotify:(ret_msg)->
        cc.log "ApplyGuildCBNotify Respond "
    ApplyGuildToOfficeCBNotify:(ret_msg)->
        cc.log "ApplyGuildToOfficeCBNotify Respond "
    BuildingCanLvUpCBNotify:(ret_msg)->
        cc.log "BuildingCanLvUpCBNotify Respond "
    OfficeChangeCBNotify:(ret_msg)->
        cc.log "OfficeChangeCBNotify Respond "
    BuildLvUpCompleteCBNotify:(ret_msg)->
        cc.log "BuildLvUpCompleteCBNotify Respond "
    GuildCurrencyChangeCBNotify:(ret_msg)->
        cc.log "GuildCurrencyChangeCBNotify Respond "


)
GuildController.getInstance = ->
    if this.instance is undefined
        model_ = GuildModel
        model_.Initialize()
        this.instance = new GuildController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = GuildController.getInstance()
    controller_)()
  
