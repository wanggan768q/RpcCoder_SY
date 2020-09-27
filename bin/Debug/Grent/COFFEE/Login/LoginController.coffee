
BaseController = require("./../../base/BaseController.coffee")
LoginModel = require("./LoginModel.coffee")



LoginController = cc.coffee.BaseControllerExtend.extend(

    ctor:(_model)->
        @_super(this, _model)
        _model.SetLoginLineUpNotifyCB(@LoginLineUpCBNotify)
        _model.SetLoginEnterGameNotifyCB(@LoginEnterGameCBNotify)

        return



    LoginLineUpCBNotify:(ret_msg)->
        cc.log "LoginLineUpCBNotify Respond "
    LoginEnterGameCBNotify:(ret_msg)->
        cc.log "LoginEnterGameCBNotify Respond "


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
  
