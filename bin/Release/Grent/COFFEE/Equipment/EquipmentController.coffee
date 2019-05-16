
BaseController = require("./../../base/BaseController.coffee")
EquipmentModel = require("./EquipmentModel.coffee")



EquipmentController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
EquipmentController.getInstance = ->
    if this.instance is undefined
        model_ = EquipmentModel
        model_.Initialize()
        this.instance = new EquipmentController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = EquipmentController.getInstance()
    controller_)()
  
