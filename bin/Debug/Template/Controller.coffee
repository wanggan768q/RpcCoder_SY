
BaseController = require("./../../base/BaseController.coffee")
$TEMPLATE$Model = require("./$TEMPLATE$Model.coffee")



$TEMPLATE$Controller = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
$CONNOTIFY$
        return



$CONNOTIFYFUNCTION$

)
$TEMPLATE$Controller.getInstance = ->
    if this.instance is undefined
        model_ = $TEMPLATE$Model
        model_.Initialize()
        this.instance = new $TEMPLATE$Controller(model_)
    return this.instance

module.exports = (()->
    if not controller_?
        controller_ = $TEMPLATE$Controller.getInstance()
    controller_)()
  
