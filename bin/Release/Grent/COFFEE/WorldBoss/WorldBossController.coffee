
BaseController = require("./../../base/BaseController.coffee")
WorldBossModel = require("./WorldBossModel.coffee")



WorldBossController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
WorldBossController.getInstance = ->
    if this.instance is undefined
        model_ = WorldBossModel
        model_.Initialize()
        this.instance = new WorldBossController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = WorldBossController.getInstance()
    controller_)()
  
