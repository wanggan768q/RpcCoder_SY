
BaseController = require("./../../base/BaseController.coffee")
CampFigthModel = require("./CampFigthModel.coffee")



CampFigthController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetCampFightContributionNotifyCB(@CampFightContributionCBNotify)
        _model.SetObjKillBroadcastNotifyCB(@ObjKillBroadcastCBNotify)
        _model.SetNpcBirthNotifyCB(@NpcBirthCBNotify)
        _model.SetKillDeadInfoNotifyCB(@KillDeadInfoCBNotify)
        _model.SetNewSeasonNotifyCB(@NewSeasonCBNotify)

        return



    CampFightContributionCBNotify:(ret_msg)->
        cc.log "CampFightContributionCBNotify Respond "
    ObjKillBroadcastCBNotify:(ret_msg)->
        cc.log "ObjKillBroadcastCBNotify Respond "
    NpcBirthCBNotify:(ret_msg)->
        cc.log "NpcBirthCBNotify Respond "
    KillDeadInfoCBNotify:(ret_msg)->
        cc.log "KillDeadInfoCBNotify Respond "
    NewSeasonCBNotify:(ret_msg)->
        cc.log "NewSeasonCBNotify Respond "


)
CampFigthController.getInstance = ->
    if this.instance is undefined
        model_ = CampFigthModel
        model_.Initialize()
        this.instance = new CampFigthController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = CampFigthController.getInstance()
    controller_)()
  
