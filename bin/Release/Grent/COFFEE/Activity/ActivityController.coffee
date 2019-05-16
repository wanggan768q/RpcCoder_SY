
BaseController = require("./../../base/BaseController.coffee")
ActivityModel = require("./ActivityModel.coffee")



ActivityController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetEliteMonsterInfoNotifyCB(@EliteMonsterInfoCBNotify)
        _model.SetOpenActivityNotifyCB(@OpenActivityCBNotify)
        _model.SetActivityTimeNotifyCB(@ActivityTimeCBNotify)
        _model.SetXingyaoRewardNotifyCB(@XingyaoRewardCBNotify)
        _model.SetOperationTimeNotifyCB(@OperationTimeCBNotify)

        return



    EliteMonsterInfoCBNotify:(ret_msg)->
        cc.log "EliteMonsterInfoCBNotify Respond "
    OpenActivityCBNotify:(ret_msg)->
        cc.log "OpenActivityCBNotify Respond "
    ActivityTimeCBNotify:(ret_msg)->
        cc.log "ActivityTimeCBNotify Respond "
    XingyaoRewardCBNotify:(ret_msg)->
        cc.log "XingyaoRewardCBNotify Respond "
    OperationTimeCBNotify:(ret_msg)->
        cc.log "OperationTimeCBNotify Respond "


)
ActivityController.getInstance = ->
    if this.instance is undefined
        model_ = ActivityModel
        model_.Initialize()
        this.instance = new ActivityController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = ActivityController.getInstance()
    controller_)()
  
