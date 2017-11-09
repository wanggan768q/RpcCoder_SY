
BaseController = require("./../../base/BaseController.coffee")
HumanModel = require("./HumanModel.coffee")



HumanController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
HumanController.getInstance = ->
    if this.instance is undefined
        model_ = HumanModel
        model_.Initialize()
        this.instance = new HumanController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = HumanController.getInstance()
    controller_)()
  
