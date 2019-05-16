
BaseController = require("./../../base/BaseController.coffee")
QuestModel = require("./QuestModel.coffee")



QuestController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetOnAcceptQuestNotifyCB(@OnAcceptQuestCBNotify)
        _model.SetOnCompleteQuestNotifyCB(@OnCompleteQuestCBNotify)
        _model.SetUpdateQuestNotifyCB(@UpdateQuestCBNotify)
        _model.SetRemoveQuestNotifyNotifyCB(@RemoveQuestNotifyCBNotify)
        _model.SetDailyQuestUpdateNotifyCB(@DailyQuestUpdateCBNotify)

        return



    OnAcceptQuestCBNotify:(ret_msg)->
        cc.log "OnAcceptQuestCBNotify Respond "
    OnCompleteQuestCBNotify:(ret_msg)->
        cc.log "OnCompleteQuestCBNotify Respond "
    UpdateQuestCBNotify:(ret_msg)->
        cc.log "UpdateQuestCBNotify Respond "
    RemoveQuestNotifyCBNotify:(ret_msg)->
        cc.log "RemoveQuestNotifyCBNotify Respond "
    DailyQuestUpdateCBNotify:(ret_msg)->
        cc.log "DailyQuestUpdateCBNotify Respond "


)
QuestController.getInstance = ->
    if this.instance is undefined
        model_ = QuestModel
        model_.Initialize()
        this.instance = new QuestController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = QuestController.getInstance()
    controller_)()
  
