#include <stdio.h>
#include <math.h>

// Problem: Determine the exact (50 floor) spot the balls break in the most optimized way.
// O(sqrt(n)) time complexity otimizado ou O(n) com linear search
int twoCrystalBalls(int n) {
    int prev = 0;
    int curr = (int)sqrt(n); // Começamos no andar sqrt(n)
    int breakFloor;
    
    // Primeira bola: Teste os andares de sqrt(n) até que a bola se quebre
    while (curr < n) {
        printf("Testando o andar %d\n", curr);
        
        // Simulamos a quebra da bola
        // Se a bola quebra no andar corrente, vamos testar o intervalo com a segunda bola
        // Se a bola não quebra, então vamos saltar mais andares
        
        // Exemplo: Vamos dizer que a bola se quebra no andar 50
        if (curr == 50) {
            printf("A primeira bola quebrou no andar %d\n", curr);
            break;
        }
        
        prev = curr;
        curr += (int)sqrt(n);  // Incrementamos em sqrt(n)
    }

    // Segunda bola: Teste linear entre prev e curr para encontrar o andar exato
    for (int i = prev + 1; i < curr; i++) {
        printf("Testando o andar %d com a segunda bola\n", i);
        
        // Simulamos a quebra da bola
        if (i == 50) {
            printf("A segunda bola quebrou no andar %d\n", i);
            return -1;
        }

        breakFloor = i;
    }
    
    // Se não encontrar, significa que não houve quebra até o andar n
    return breakFloor;
}

int main() {
    int n = 100;  // Total de andares no edifício
    int result = twoCrystalBalls(n);

    if (result == -1) {
        printf("A bola quebrou no andar %d\n", result);
    } else {
        printf("A bola parte a partir do andar %d\n", result);
    }

    return 0;
}
