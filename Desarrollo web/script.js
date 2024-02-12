function eraseContent(){


const layer= document.getElementById("stylelayer")

layer.innerHTML=""

}

document.getElementById("Buttonerase").addEventListener("click",()=>{

    eraseContent()

})

const aux= document.querySelector("#stylelayer")

aux.style


function addContent(){

    const layered = document.querySelector("#stylelayer")

    if (layered) {
        const newText = prompt("Digite el nuevo contenido:");

        if (newText !== null) {
            const textNode = document.createTextNode(newText);
            
            layered.appendChild(textNode);
        } else {
            console.log("Operación cancelada por el usuario.");
        }
    } else {
        console.error("No se encontró ningún elemento con la clase 'stylelayer'.");
    }
    
}

document.getElementById("Buttonadd").addEventListener("click",()=>{

    addContent()

})

document.querySelector("#ButtonSumar").addEventListener("click", ()=>{

    const One=  parseInt(document.getElementById("numOne").value)
    const two= parseInt( document.getElementById("numTwo").value)
    

    alert("El resultado de la suma es igual a: "+(One+two)+ " !")


})

document.querySelector("#numOne").addEventListener('keypress', (event)=>{


    if(/[^0-9]/.test(event.key)){

        event.preventDefault()

    }else{



    }

})
