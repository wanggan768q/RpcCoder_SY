
BaseController = require("./../../base/BaseController.coffee")
BaseAttrModel = require("./BaseAttrModel.coffee")



BaseAttrController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
BaseAttrController.getInstance = ->
    if this.instance is undefined
        model_ = BaseAttrModel
        model_.Initialize()
        this.instance = new BaseAttrController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = BaseAttrController.getInstance()
    controller_)()
  
