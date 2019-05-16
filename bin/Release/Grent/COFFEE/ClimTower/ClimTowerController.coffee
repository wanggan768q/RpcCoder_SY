
BaseController = require("./../../base/BaseController.coffee")
ClimTowerModel = require("./ClimTowerModel.coffee")



ClimTowerController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetOpenRuleNotifyCB(@OpenRuleCBNotify)
        _model.SetNextLayerNotifyCB(@NextLayerCBNotify)
        _model.SetChallengeEndNotifyCB(@ChallengeEndCBNotify)

        return



    OpenRuleCBNotify:(ret_msg)->
        cc.log "OpenRuleCBNotify Respond "
    NextLayerCBNotify:(ret_msg)->
        cc.log "NextLayerCBNotify Respond "
    ChallengeEndCBNotify:(ret_msg)->
        cc.log "ChallengeEndCBNotify Respond "


)
ClimTowerController.getInstance = ->
    if this.instance is undefined
        model_ = ClimTowerModel
        model_.Initialize()
        this.instance = new ClimTowerController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = ClimTowerController.getInstance()
    controller_)()
  
