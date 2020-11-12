let data = [
    {
        "Data": "2020-9-27 19:43:07",
        "Temperatura": "1",
        "Pressão": 2,
        "Humidade": 60,
        "Co2": 40,
        "Poeira": 30

    },
    {
        "Data": "2020-9-27 19:43:07",
        "Temperatura": "1",
        "Pressão": 2,
        "Humidade": 60,
        "Co2": 40,
        "Poeira": 30

    },
    {
        "Data": "2020-9-27 19:43:07",
        "Temperatura": "1",
        "Pressão": 2,
        "Humidade": 60,
        "Co2": 40,
        "Poeira": 30

    },
    {
        "Data": "2020-9-27 19:43:07",
        "Temperatura": "1",
        "Pressão": 2,
        "Humidade": 60,
        "Co2": 40,
        "Poeira": 30

    },
    {
        "Data": "2020-9-27 19:43:07",
        "Temperatura": "1",
        "Pressão": 2,
        "Humidade": 60,
        "Co2": 40,
        "Poeira": 30
    }

]
class DataTable {
    constructor(data) {
        this.table = document.createElement("table");

        ["caption", "colgroup", "thead", "tbody"].forEach(e => {
            this[e] = document.createElement(e);
            this.table.appendChild(this[e]);
        });

        if (data && data.headers) {
            data.headers.forEach(h => this.insertHeader(h));
        }
    }

    insertHeader(name) {
        let h = document.createElement("th");
        h.scope = "col"
        h.innerHTML = name;

        this.thead.appendChild(h);
    }

    insertRow(data, below) {
        let tr = document.createElement("tr");
        tr.classList.add(`row-${data.id}`);

        let id = [...this.table.querySelectorAll("tbody > tr")].length;

        Object.keys(data).forEach(d => {
            let td = document.createElement("td");
            td.classList.add(`user-${d}`);

            let div = document.createElement("div");
            div.innerHTML = data[d];

            td.appendChild(div);

            tr.appendChild(td);
        });

        if (below === "below") {
            this.tbody.appendChild(tr);
        } else {
            this.tbody.insertBefore(tr, this.table.querySelector("tbody > tr"));
        }
    }

    deleteRowPop() {
        [...this.table.querySelectorAll("tbody > tr")].pop().remove()
    }

    deleteRowShift() {
        let row = [...this.table.querySelectorAll("tbody > tr")].shift();
        row.remove();

        return row;
    }

    deleteRowByOrder(i) {
        [...this.table.querySelectorAll("tbody > tr")][i].remove()
    }

    deleteRowById(id) {

    }
}

let dataTable = new DataTable();

async function generateTable(table, data) {
    let div = document.querySelector("div.table");
    div.appendChild(table.table);

    table.table.id = "customers";

    data.forEach(d => table.insertRow(d));

    table.headers = Object.keys(data[0]);
    table.headers.forEach(h => {
        table.insertHeader(h);
    });

    //console.log(dataSet["Alt"]);
}

function loadCSS(url, doc) {
    doc.setAttribute('type', "text/css");
    doc.setAttribute('rel', "stylesheet");
    doc.setAttribute('href', url);
    document.getElementsByTagName("head").item(0).appendChild(doc);
}

async function getData(url) {
    let res = await fetch(url, {
        method: "GET",
        headers: {
            "Content-Type": "application/json",
        }
    });

    let text = await res.text();
    let data = JSON.parse(text);

    return data;
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

async function main() {
    //let data = await getData("/api/measure/estacao1");  
    generateTable(dataTable, data);
    eventSetup();
}

function eventSetup() {
    let search = document.getElementById("search");
    search.addEventListener("click", (e) => {
        e.preventDefault();

        let data_to_send = {};
        data_to_send.date = document.getElementById("date").value;
        data_to_send.sample = document.getElementById("sample").value;
        data_to_send.avg = document.getElementById("avg").checked;
        data_to_send.desc = document.getElementById("desc").checked;

        sendFilters("http://192.168.0.123:3000/search", data_to_send);
    })
}

main();