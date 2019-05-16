
BaseController = require("./../../base/BaseController.coffee")
ShopModel = require("./ShopModel.coffee")



ShopController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
ShopController.getInstance = ->
    if this.instance is undefined
        model_ = ShopModel
        model_.Initialize()
        this.instance = new ShopController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = ShopController.getInstance()
    controller_)()
  
