
BaseController = require("./../../base/BaseController.coffee")
LoginModel = require("./LoginModel.coffee")



LoginController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
LoginController.getInstance = ->
    if this.instance is undefined
        model_ = LoginModel
        model_.Initialize()
        this.instance = new LoginController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = LoginController.getInstance()
    controller_)()
  
