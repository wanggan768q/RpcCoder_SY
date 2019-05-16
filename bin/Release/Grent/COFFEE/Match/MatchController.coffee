
BaseController = require("./../../base/BaseController.coffee")
MatchModel = require("./MatchModel.coffee")



MatchController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetCancelMatchNotifyNotifyCB(@CancelMatchNotifyCBNotify)
        _model.SetPrepareRoomNotifyCB(@PrepareRoomCBNotify)
        _model.SetRoomCancelNotifyCB(@RoomCancelCBNotify)
        _model.SetMemberReadyNotifyCB(@MemberReadyCBNotify)

        return



    CancelMatchNotifyCBNotify:(ret_msg)->
        cc.log "CancelMatchNotifyCBNotify Respond "
    PrepareRoomCBNotify:(ret_msg)->
        cc.log "PrepareRoomCBNotify Respond "
    RoomCancelCBNotify:(ret_msg)->
        cc.log "RoomCancelCBNotify Respond "
    MemberReadyCBNotify:(ret_msg)->
        cc.log "MemberReadyCBNotify Respond "


)
MatchController.getInstance = ->
    if this.instance is undefined
        model_ = MatchModel
        model_.Initialize()
        this.instance = new MatchController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = MatchController.getInstance()
    controller_)()
  
