
BaseController = require("./../../base/BaseController.coffee")
PetModel = require("./PetModel.coffee")



PetController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
PetController.getInstance = ->
    if this.instance is undefined
        model_ = PetModel
        model_.Initialize()
        this.instance = new PetController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = PetController.getInstance()
    controller_)()
  
