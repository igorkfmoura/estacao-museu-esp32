function setupEvents() {
    //  switch configs events
    let db_nav = document.getElementById("db_nav");
    let wifi_nav = document.getElementById("wifi_nav");

    wifi_nav.addEventListener("click", () => {
        let db_config = document.getElementsByClassName("db_config")[0];
        let wifi_config = document.getElementsByClassName("wifi_config")[0];
        db_config.style.display = "none";
        db_nav.style.backgroundColor = "#FFF"
        wifi_config.style.display = "flex";
        wifi_nav.style.backgroundColor = "grey"
    })

    db_nav.addEventListener("click", () => {
        let db_config = document.getElementsByClassName("db_config")[0];
        let wifi_config = document.getElementsByClassName("wifi_config")[0];
        db_config.style.display = "flex";
        db_nav.style.backgroundColor = "grey"
        wifi_config.style.display = "none";
        wifi_nav.style.backgroundColor = "#FFF"
    })

    //  DB configs

    let save_sample_time = document.getElementById("save_sample_time");
    save_sample_time.addEventListener("click", (e) => {
        e.preventDefault();
        let data_to_send = {};
        data_to_send.sample = document.getElementById("data_sample").value;
        //console.log(data_to_send)
        sendFilters("http://192.168.0.123:3000/db_config/sample_time", data_to_send)
    });

    let download_db = document.getElementById("download_db");
    download_db.addEventListener("click", (e) => {
        e.preventDefault();
        console.log("DB downloaded");
    });

    let reset_config = document.getElementById("reset_config");
    reset_config.addEventListener("click", (e) => {
        e.preventDefault();
        console.log("Configs reseted");
    });

    //  Wifi configs

    let save_wifi_config = document.getElementById("save_wifi_config")
    save_wifi_config.addEventListener("click", (e) => {
        e.preventDefault();
        let data_to_send = {};
        data_to_send.ssid = document.getElementById("ssid").value;
        data_to_send.pass = document.getElementById("pass").value;
        //console.log(data_to_send)
        sendFilters("http://192.168.0.123:3000/wifi_config", data_to_send);
    })

}
async function sendFilters(url, data_send) {
    let res = await fetch(url, {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify(data_send)
    });

    let text = await res.text();
    let data = JSON.parse(text);

    return data;
}

function main() {
    setupEvents();
}

main();
