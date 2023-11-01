const btn_menu = document.getElementById('btn_menu');
const carreras = document.querySelector('.oculto');
const carrousel = document.querySelector('.carrousel');

addEventListener('DOMContentLoaded', ()=> {
    let contador = 1;
    setInterval(()=> {
    contador++;
    carrousel.style.backgroundImage = `url('assets/img/imagen${contador}.jpg')`;
    if(contador == 4){
        contador = 1;
    }
    
    }, 5000)
})

btn_menu.addEventListener('click', ()=> {
carreras.classList.toggle('visible');
})

