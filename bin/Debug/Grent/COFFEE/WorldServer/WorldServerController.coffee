
BaseController = require("./../../base/BaseController.coffee")
WorldServerModel = require("./WorldServerModel.coffee")



WorldServerController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
WorldServerController.getInstance = ->
    if this.instance is undefined
        model_ = WorldServerModel
        model_.Initialize()
        this.instance = new WorldServerController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = WorldServerController.getInstance()
    controller_)()
  
