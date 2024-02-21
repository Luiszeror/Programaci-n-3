document.querySelector("#sendInfo").addEventListener("click",()=>{

    const nOne= document.querySelector("#NumOne").value
    const nTwo= document.querySelector("#NumTwo").value

    console.log(nOne +","+ nTwo)


})


const xhr= new XMLHttpRequest()
xhr.open("GET", "https//localhost/tes.php")