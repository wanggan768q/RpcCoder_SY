
BaseController = require("./../../base/BaseController.coffee")
WGModel = require("./WGModel.coffee")



WGController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)

        return





)
WGController.getInstance = ->
    if this.instance is undefined
        model_ = WGModel
        model_.Initialize()
        this.instance = new WGController(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = WGController.getInstance()
    controller_)()
  
