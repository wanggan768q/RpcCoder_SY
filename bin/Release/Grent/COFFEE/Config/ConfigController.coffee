
BaseController = require("./../../base/BaseController.coffee")
ConfigModel = require("./ConfigModel.coffee")



ConfigController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
ConfigController.getInstance = ->
    if this.instance is undefined
        model_ = ConfigModel
        model_.Initialize()
        this.instance = new ConfigController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = ConfigController.getInstance()
    controller_)()
  
