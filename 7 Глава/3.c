#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int n;
    int c_h = 0, c_n_h = 0;
    float m_v_h = 0, m_v_n_h = 0;
    scanf("%d", &n);
    while (n != 0) {
        if (n % 2 == 0) {
            ++c_h;
            m_v_h += n;
        }
        else {
            ++c_n_h;
            m_v_n_h += n;
        }
        fflush(stdin);
        scanf("%d", &n);
    }
    m_v_h /= (float)c_h, m_v_n_h /= (float)c_n_h;
    printf("Chet:     %d %f\n", c_h, m_v_h);
    printf("Not chet: %d %f\n", c_n_h, m_v_n_h);
    return 0;
}