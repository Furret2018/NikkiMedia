function search(type) {
    let uid = $("#uid").val();
    if (uid === "") {
        alert("请输入用户编号");
        return;
    }
    operateOk(false);
    $.ajax({
        "url": "./image",
        "type": "POST",
        "data": {
            "uid": uid,
            "type": type
        },
        "dataType": "json",
        "success": function (data) {
            operateOk(true);
            if (data['status'] === 1) {
                show(data['data']);
                return;
            }
            alert(data ['message']);
            $("#show").html("");
        },
        "error": function () {
            alert("数据获取失败，请重试！");
            $("#show").html("");
            operateOk(true);
        }
    })
}


function show(data) {
    let show = $("#show");
    show.html("");
    for (let i = 0; i < data.length; i++) {
        let u = data[i];
        let img = $('<img src="' + u + '" alt="头像" width="45%"/>');
        show.append(img);
    }
}


function operateOk(flag) {
    let submit = $("#submit");
    if (flag) {
        submit.removeAttr("disabled");
        submit.html("查询")
    } else {
        submit.attr("disabled", "disabled");
        submit.html("查询中...")
    }
}