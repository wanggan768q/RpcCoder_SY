
BaseController = require("./../../base/BaseController.coffee")
DungeonModel = require("./DungeonModel.coffee")



DungeonController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetSettlementNotifyCB(@SettlementCBNotify)
        _model.SetDungeonDataNotifyCB(@DungeonDataCBNotify)
        _model.SetDungeonTargetNotifyCB(@DungeonTargetCBNotify)
        _model.SetTargetContentChangeNotifyCB(@TargetContentChangeCBNotify)
        _model.SetDungeon_NotifyNotifyCB(@Dungeon_NotifyCBNotify)
        _model.SetForceEnterNextDungeonLayerNotifyCB(@ForceEnterNextDungeonLayerCBNotify)
        _model.SetDungeonRewardUpdateNotifyCB(@DungeonRewardUpdateCBNotify)
        _model.SetVictoryOfAllLayerNotifyCB(@VictoryOfAllLayerCBNotify)
        _model.SetLayerBeginNotifyCB(@LayerBeginCBNotify)
        _model.SetLayerSettlementNotifyCB(@LayerSettlementCBNotify)
        _model.SetSceneOperatorNNotifyCB(@SceneOperatorNCBNotify)
        _model.SetEnterLayerDungeonNotifyCB(@EnterLayerDungeonCBNotify)
        _model.SetDungeonExploitsNotifyCB(@DungeonExploitsCBNotify)

        return



    SettlementCBNotify:(ret_msg)->
        cc.log "SettlementCBNotify Respond "
    DungeonDataCBNotify:(ret_msg)->
        cc.log "DungeonDataCBNotify Respond "
    DungeonTargetCBNotify:(ret_msg)->
        cc.log "DungeonTargetCBNotify Respond "
    TargetContentChangeCBNotify:(ret_msg)->
        cc.log "TargetContentChangeCBNotify Respond "
    Dungeon_NotifyCBNotify:(ret_msg)->
        cc.log "Dungeon_NotifyCBNotify Respond "
    ForceEnterNextDungeonLayerCBNotify:(ret_msg)->
        cc.log "ForceEnterNextDungeonLayerCBNotify Respond "
    DungeonRewardUpdateCBNotify:(ret_msg)->
        cc.log "DungeonRewardUpdateCBNotify Respond "
    VictoryOfAllLayerCBNotify:(ret_msg)->
        cc.log "VictoryOfAllLayerCBNotify Respond "
    LayerBeginCBNotify:(ret_msg)->
        cc.log "LayerBeginCBNotify Respond "
    LayerSettlementCBNotify:(ret_msg)->
        cc.log "LayerSettlementCBNotify Respond "
    SceneOperatorNCBNotify:(ret_msg)->
        cc.log "SceneOperatorNCBNotify Respond "
    EnterLayerDungeonCBNotify:(ret_msg)->
        cc.log "EnterLayerDungeonCBNotify Respond "
    DungeonExploitsCBNotify:(ret_msg)->
        cc.log "DungeonExploitsCBNotify Respond "


)
DungeonController.getInstance = ->
    if this.instance is undefined
        model_ = DungeonModel
        model_.Initialize()
        this.instance = new DungeonController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = DungeonController.getInstance()
    controller_)()
  
