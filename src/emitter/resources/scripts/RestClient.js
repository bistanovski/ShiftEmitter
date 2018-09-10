var serverEndpoint = "http://127.0.0.1:8000"
var apiVersion = "/api/v1"
var restServerEndpoint = serverEndpoint + apiVersion

var HTTP_METHOD = {
    GET  : "GET",
    HEAD : "HEAD",
    POST : "POST"
};

function sendRequest(httpMethod, url, data, onResponseCallback) {
    var Backend = new XMLHttpRequest();

    Backend.open(httpMethod, restServerEndpoint + "/users");
    Backend.onreadystatechange = function() {
        if (Backend.readyState === XMLHttpRequest.DONE) {
            if(null !== onResponseCallback) {
                if(200 != Backend.status) {
                    onResponseCallback(false, Backend.statusText)
                }
                else {
                    onResponseCallback(true, JSON.parse(Backend.responseText));
                }
            }
        }
    }

    Backend.send(data);
}

function getAllUsers(onResponseCallback) {
    sendRequest(HTTP_METHOD.GET, "/users", null, onResponseCallback);
}
