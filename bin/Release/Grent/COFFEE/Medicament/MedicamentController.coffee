
BaseController = require("./../../base/BaseController.coffee")
MedicamentModel = require("./MedicamentModel.coffee")



MedicamentController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetServerRefreshMedicamentNotifyCB(@ServerRefreshMedicamentCBNotify)
        _model.SetMedicamentCDNotifyNotifyCB(@MedicamentCDNotifyCBNotify)

        return



    ServerRefreshMedicamentCBNotify:(ret_msg)->
        cc.log "ServerRefreshMedicamentCBNotify Respond "
    MedicamentCDNotifyCBNotify:(ret_msg)->
        cc.log "MedicamentCDNotifyCBNotify Respond "


)
MedicamentController.getInstance = ->
    if this.instance is undefined
        model_ = MedicamentModel
        model_.Initialize()
        this.instance = new MedicamentController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = MedicamentController.getInstance()
    controller_)()
  
