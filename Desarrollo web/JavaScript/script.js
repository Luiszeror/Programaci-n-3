function begin(min, max) {
  const titleTh = document.querySelector("#titleTh");

  const title = document.createTextNode(
    `Números Primos desde ${min} hasta ${max}`
  );

  titleTh.innerHTML = "";

  titleTh.appendChild(title);
}

const isCousing = (n) => {
  var cont = 2;
  var cousing = true;
  while (cont <= n / 2 && cousing) {
    cousing = !(n % cont++ == 0);
  }

  return cousing;
};

document.querySelector("#btnExecute").addEventListener("click", () => {
  const nOne = parseInt(document.querySelector("#nOne").value);
  const nTwo = parseInt(document.querySelector("#nTwo").value);

  const min = nOne < nTwo ? nOne : nTwo;
  const max = nOne > nTwo ? nOne : nTwo;

  begin(min, max);
  const tBody = document.querySelector("#tBody");
  tBody.innerHTML = ""
  var cont = 1
  var sum = 0
  for (var number = min; number <= max; number++) {
    
    if (isCousing(number)) {
      sum += number

      const row = document.createElement("tr");

      const colNum = document.createElement("td");
      colNum.appendChild(document.createTextNode(cont++));
      row.appendChild(colNum);

      const colVal = document.createElement("td")
      

      if(cont%2==0){
        colVal.setAttribute("style","background-color:white ")

        colNum.setAttribute("style", "background-color: #CDE351")
        
      }else{
        colVal.setAttribute("style","background-color:#3ACF62 ")
        colNum.setAttribute("style", "background-color: white")


      }
      
      colVal.appendChild( document.createTextNode(number))
      row.appendChild(colVal)

      tBody.appendChild(row);

      

    }
  }

  const titFoot = document.createTextNode(`Hay ${--cont} primos y la suma es ${sum}`)
  

  document.querySelector("#foot").innerHTML = ""
  document.querySelector("#foot").appendChild(titFoot)
});