const animales = ["el lobo", "el toro"]; // 100 animales

const LlamarA = {};

console.log("Sal de ahí chivita chivita, sal de ahí de ese lugar");
let actualmente = "la chiva";

function elementoRandom(arr) {
  const randomIndex = Math.floor(Math.random() * arr.length);
  return arr[randomIndex];
}

function realizar(N) {
  for (let i = 0; i < N; i++) {
    const prox = elementoRandom(animales);
    LlamarA[actualmente] = prox;
    console.log("Hay que llamar a " + prox + " para que saque a " + actualmente);
    actualmente = prox;

    const remover = [];
    let inspeccionar = "la chiva";

    while (!(inspeccionar in LlamarA)) {
      remover.unshift(LlamarA[inspeccionar] + " no quiere sacar a " + inspeccionar);
      inspeccionar = LlamarA[inspeccionar];
    }

    for (let i = 0; i < remover.length; i++) {
      console.log(remover[i]);
    }

    console.log("La chiva no quiere salir de ahí. Sal de ahí chivita chivita, sal de ahí de ese lugar");
  }
}

// Tiempo esperado de ejecución
console.log("Tiempo esperado de ejecución:");
console.log("N = 1, Tiempo: " + (1 * 7) + " milisegundos"); // 7 líneas
console.log("N = 10, Tiempo: " + (10 * 7) + " milisegundos"); // 7 líneas ejecutadas 10 veces
console.log("N = 50, Tiempo: " + (50 * 7) + " milisegundos"); // 7 líneas ejecutadas 50 veces
console.log("N = 200, Tiempo: " + (200 * 7) + " milisegundos"); // 7 líneas ejecutadas 200 veces

// Ejecución del pseudocódigo
realizar(10); // Puedes cambiar el valor de N aquí
