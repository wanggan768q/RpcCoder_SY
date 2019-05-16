
BaseController = require("./../../base/BaseController.coffee")
GameSettingModel = require("./GameSettingModel.coffee")



GameSettingController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
GameSettingController.getInstance = ->
    if this.instance is undefined
        model_ = GameSettingModel
        model_.Initialize()
        this.instance = new GameSettingController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = GameSettingController.getInstance()
    controller_)()
  
