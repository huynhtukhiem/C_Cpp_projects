#include<stdio.h>
#include<windows.h> // Thư viện này dùng để in ra tiếng việt trong hàm main
#include<time.h> // Thư viện này dùng để sinh số ngẫu nhiên
#include<stdlib.h>

// Khai báo prototype
void Sum_2_1_number(); // Hàm cộng 2 số có 1 chữ số
void Sum_2_2_number(); // Hàm cộng 2 số có 2 chữ số
void Sum_N_M_number(); // Hàm cộng N số có M chữ số
void Sum_N_number(); // Hàm cộng N số ngẫu nhiên
void Subtract_2_1_number(); // Hàm trừ 2 số có 1 chữ số
void Subtract_2_2_number(); // Hàm trừ 2 số có 2 chữ số
void Subtract_N_M_number(); // Hàm trừ N số có M chữ số
void Subtract_N_number(); // Hàm trừ N số ngẫu nhiên
void Multiply_2_1_number(); // Hàm nhân 2 số có 1 chữ số
void Multiply_2_2_number(); // Hàm nhân 2 số có 2 chữ số
void Multiply_N_M_number(); // Hàm nhân N số có M chữ số
void Multiply_N_number(); // Hàm nhân N số ngẫu nhiên
void Divide_2_1_number(); // Hàm chia 2 số có 1 chữ số
void Divide_2_2_number(); // Hàm chia 2 số có 2 chữ số
void Divide_N_M_number(); // Hàm chia N số có M chữ số
void Divide_N_number(); // Hàm chia N số ngẫu nhiên

// Hàm cộng 2 số có 1 chữ số
void Sum_2_1_number(){ 
    int a = rand() % 10; // từ 0 -> 9
    int b = rand() % 10; // từ 0 -> 9
    int sum = a + b;
    int result;
    printf("Phép cộng 2 số có 1 chữ số: %d + %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(sum == result){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d + %d = %d\n", a, b, sum);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d + %d = %d\n", a, b, sum);
    }
}

// Hàm cộng 2 số có 2 chữ số
void Sum_2_2_number(){ 
    int a = rand() % 90 + 10; // 2 chữ số
    int b = rand() % 90 + 10;
    int sum = a + b;
    int result;
    printf("Phép cộng 2 số có 2 chữ số: %d + %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(sum == result){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d + %d = %d\n", a, b, sum);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d + %d = %d\n", a, b, sum);
    }
}

// Hàm cộng N số có M chữ số
void Sum_N_M_number(){
    int n, m;
    printf("Nhập số lượng số muốn cộng: ");
    scanf("%d", &n);
    printf("Nhập số chữ số: ");
    scanf("%d", &m);
    if(n <= 0 || m <= 0){
        printf("Không hợp lệ\n");
        return;
    }
  
    int min = 1;
    for(int i = 1; i < m; i++){
        min *= 10;
    }
    int max = min * 10 - 1;

    long long sum = 0;
    printf("Phép cộng %d số có %d chữ số: ", n, m);
    for(int i = 0; i < n; i++){
        int num = rand() % (max - min + 1) + min;
        sum += num;
        printf("%d", num);
        if(i < n - 1){
            printf(" + ");
        }
    }

    long long result;
    printf("\n> ");
    scanf("%lld", &result);
    if(result == sum){
        printf("Chính xác!! Tổng là: %lld\n", sum);
    }
    else{
        printf("Không chính xác!! Tổng là: %lld\n", sum);
    }
}

// Hàm cộng N số ngẫu nhiên
void Sum_N_number(){
    int n;
    long long sum = 0;
    printf("Nhập số lượng số tính tổng: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Không hợp lệ\n");
        return;
    }
    for(int i = 0; i < n; i++){
        int num = rand() % 1000000;
        sum += num;
        printf("%d", num);
        if(i < n - 1){
            printf(" + ");
        }
    }
    long long result;
    printf("\n> ");
    scanf("%lld", &result);
    if(result == sum){
        printf("Chính xác!! Tổng là: %lld\n", sum);
    }
    else{
        printf("Không chính xác!! Tổng là: %lld\n", sum);
    }
}

// Hàm trừ 2 số có 1 chữ số
void Subtract_2_1_number(){
    int a = rand() % 10;
    int b = rand() % (a + 1); // Đảm bảo b <= a để tránh kết quả âm
    int result, diff = a - b;
    printf("Phép trừ 2 số có 1 chữ số: %d - %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(result == diff){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d - %d = %d\n", a, b, diff);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d - %d = %d\n", a, b, diff);
    }
}

// Hàm trừ 2 số có 2 chữ số
void Subtract_2_2_number(){
    int a = rand() % 90 + 10;
    int b = rand() % (a - 10 + 1) + 10; // Đảm bảo b <= a
    int result, diff = a - b;
    printf("Phép trừ 2 số có 2 chữ số: %d - %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(result == diff){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d - %d = %d\n", a, b, diff);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d - %d = %d\n", a, b, diff);
    }
}

// Hàm trừ N số có M chữ số
void Subtract_N_M_number(){
    int n, m;
    printf("Nhập số lượng số muốn trừ: ");
    scanf("%d", &n);
    printf("Nhập số chữ số: ");
    scanf("%d", &m);
    if(n <= 0 || m <= 0){
        printf("Không hợp lệ\n");
        return;
    }
  
    int min = 1;
    for(int i = 1; i < m; i++){
        min *= 10;
    }
    int max = min * 10 - 1;

    long long result = rand() % (max - min + 1) + min; // Số đầu tiên
    printf("Phép trừ %d số có %d chữ số: %lld", n, m, result);
    for(int i = 1; i < n; i++){
        int num = rand() % (max - min + 1) + min;
        result -= num;
        printf(" - %d", num);
    }

    long long user_result;
    printf("\n> ");
    scanf("%lld", &user_result);
    if(user_result == result){
        printf("Chính xác!! Kết quả là: %lld\n", result);
    }
    else{
        printf("Không chính xác!! Kết quả là: %lld\n", result);
    }
}

// Hàm trừ N số ngẫu nhiên
void Subtract_N_number(){
    int n;
    printf("Nhập số lượng số muốn trừ: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Không hợp lệ\n");
        return;
    }
    long long result = rand() % 1000000;
    printf("Phép trừ %d số ngẫu nhiên: %lld", n, result);
    for(int i = 1; i < n; i++){
        int num = rand() % 1000000;
        result -= num;
        printf(" - %d", num);
    }
    long long user_result;
    printf("\n> ");
    scanf("%lld", &user_result);
    if(user_result == result){
        printf("Chính xác!! Kết quả là: %lld\n", result);
    }
    else{
        printf("Không chính xác!! Kết quả là: %lld\n", result);
    }
}

// Hàm nhân 2 số có 1 chữ số
void Multiply_2_1_number(){
    int a = rand() % 10;
    int b = rand() % 10;
    int result, product = a * b;
    printf("Phép nhân 2 số có 1 chữ số: %d * %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(result == product){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d * %d = %d\n", a, b, product);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d * %d = %d\n", a, b, product);
    }
}

// Hàm nhân 2 số có 2 chữ số
void Multiply_2_2_number(){
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;
    int result, product = a * b;
    printf("Phép nhân 2 số có 2 chữ số: %d * %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(result == product){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d * %d = %d\n", a, b, product);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d * %d = %d\n", a, b, product);
    }
}

// Hàm nhân N số có M chữ số
void Multiply_N_M_number(){
    int n, m;
    printf("Nhập số lượng số muốn nhân: ");
    scanf("%d", &n);
    printf("Nhập số chữ số: ");
    scanf("%d", &m);
    if(n <= 0 || m <= 0){
        printf("Không hợp lệ\n");
        return;
    }
  
    int min = 1;
    for(int i = 1; i < m; i++){
        min *= 10;
    }
    int max = min * 10 - 1;

    long long product = 1;
    printf("Phép nhân %d số có %d chữ số: ", n, m);
    for(int i = 0; i < n; i++){
        int num = rand() % (max - min + 1) + min;
        product *= num;
        printf("%d", num);
        if(i < n - 1){
            printf(" * ");
        }
    }

    long long result;
    printf("\n> ");
    scanf("%lld", &result);
    if(result == product){
        printf("Chính xác!! Kết quả là: %lld\n", product);
    }
    else{
        printf("Không chính xác!! Kết quả là: %lld\n", product);
    }
}

// Hàm nhân N số ngẫu nhiên
void Multiply_N_number(){
    int n;
    printf("Nhập số lượng số muốn nhân: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Không hợp lệ\n");
        return;
    }
    long long product = 1;
    printf("Phép nhân %d số ngẫu nhiên: ", n);
    for(int i = 0; i < n; i++){
        int num = rand() % 1000 + 1; // Giới hạn để tránh tràn số
        product *= num;
        printf("%d", num);
        if(i < n - 1){
            printf(" * ");
        }
    }
    long long result;
    printf("\n> ");
    scanf("%lld", &result);
    if(result == product){
        printf("Chính xác!! Kết quả là: %lld\n", product);
    }
    else{
        printf("Không chính xác!! Kết quả là: %lld\n", product);
    }
}

// Hàm chia 2 số có 1 chữ số
void Divide_2_1_number(){
    int b = rand() % 9 + 1; // Tránh chia cho 0
    int quotient = rand() % 10;
    int a = b * quotient; // Đảm bảo chia hết
    int result;
    printf("Phép chia 2 số có 1 chữ số: %d / %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(result == quotient){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d / %d = %d\n", a, b, quotient);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d / %d = %d\n", a, b, quotient);
    }
}

// Hàm chia 2 số có 2 chữ số
void Divide_2_2_number(){
    int b = rand() % 90 + 10; // Tránh chia cho 0
    int quotient = rand() % 90 + 10;
    int a = b * quotient; // Đảm bảo chia hết
    int result;
    printf("Phép chia 2 số có 2 chữ số: %d / %d\n", a, b);
    printf("> ");
    scanf("%d", &result);
    if(result == quotient){
        printf("Chính xác!!!\n");
        printf("Đáp án: %d / %d = %d\n", a, b, quotient);
    }
    else{
        printf("Không chính xác!!!\n");
        printf("Đáp án: %d / %d = %d\n", a, b, quotient);
    }
}

// Hàm chia N số có M chữ số
void Divide_N_M_number(){
    int n, m;
    printf("Nhập số lượng số muốn chia: ");
    scanf("%d", &n);
    printf("Nhập số chữ số: ");
    scanf("%d", &m);
    if(n <= 0 || m <= 0){
        printf("Không hợp lệ\n");
        return;
    }
  
    int min = 1;
    for(int i = 1; i < m; i++){
        min *= 10;
    }
    int max = min * 10 - 1;

    long long result = rand() % (max - min + 1) + min;
    printf("Phép chia %d số có %d chữ số: %lld", n, m, result);
    for(int i = 1; i < n; i++){
        int num = rand() % (max - min + 1) + min;
        result *= num; // Nhân ngược để đảm bảo chia hết
        printf(" / %d", num);
    }

    long long user_result;
    printf("\n> ");
    scanf("%lld", &user_result);
    if(user_result == result){
        printf("Chính xác!! Kết quả là: %lld\n", result);
    }
    else{
        printf("Không chính xác!! Kết quả là: %lld\n", result);
    }
}

// Hàm chia N số ngẫu nhiên
void Divide_N_number(){
    int n;
    printf("Nhập số lượng số muốn chia: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Không hợp lệ\n");
        return;
    }
    long long result = rand() % 1000 + 1;
    printf("Phép chia %d số ngẫu nhiên: %lld", n, result);
    for(int i = 1; i < n; i++){
        int num = rand() % 999 + 1; // Tránh chia cho 0
        result *= num; // Nhân ngược để đảm bảo chia hết
        printf(" / %d", num);
    }
    long long user_result;
    printf("\n> ");
    scanf("%lld", &user_result);
    if(user_result == result){
        printf("Chính xác!! Kết quả là: %lld\n", result);
    }
    else{
        printf("Không chính xác!! Kết quả là: %lld\n", result);
    }
}

int main(){
    SetConsoleOutputCP(65001);
    srand(time(NULL)); // Khởi tạo seed để random số
    int choice; // Biến chọn chức năng trong menu chính
    int subchoice; // Biến chọn chức năng phụ
    char again; // Biến chọn tiếp tục hoặc dừng lại

    while(1){
        system("cls");
        printf("=======Trò chơi tính toán=======\n");
        printf("1: Phép cộng\n");
        printf("2: Phép trừ\n");
        printf("3: Phép nhân\n");
        printf("4: Phép chia\n");
        printf("0: Thoát\n");
        printf("Mời bạn chọn: ");
        scanf("%d", &choice);

        if(choice == 0) break; // Thoát chương trình

        // Chọn chức năng chính
        switch(choice){
            // Trò chơi phép cộng
            case 1:{
                do{
                    system("cls");
                    printf("=======Phép toán cộng=======\n");
                    printf("1: Cộng 2 số có 1 chữ số\n");
                    printf("2: Cộng 2 số có 2 chữ số\n");
                    printf("3: Cộng N số có M chữ số\n");
                    printf("4: Cộng N số ngẫu nhiên\n");
                    printf("0: Về trang chủ\n");
                    printf("Mời bạn chọn: ");
                    scanf("%d", &subchoice);

                    // Chọn trò chơi phụ
                    switch(subchoice){
                        case 1:{
                            do{
                                system("cls");
                                Sum_2_1_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 2:{
                            do{
                                system("cls");
                                Sum_2_2_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 3:{
                            do{
                                system("cls");
                                Sum_N_M_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 4:{
                            do{
                                system("cls");
                                Sum_N_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 0:
                            break;
                        default:{
                            printf("Lựa chọn không hợp lệ!\n");
                            system("pause");
                            break;
                        }
                    }
                }while(subchoice != 0);
                break;
            }

            // Phép trừ
            case 2:{
                do{
                    system("cls");
                    printf("=======Phép toán trừ=======\n");
                    printf("1: Trừ 2 số có 1 chữ số\n");
                    printf("2: Trừ 2 số có 2 chữ số\n");
                    printf("3: Trừ N số có M chữ số\n");
                    printf("4: Trừ N số ngẫu nhiên\n");
                    printf("0: Về trang chủ\n");
                    printf("Mời bạn chọn: ");
                    scanf("%d", &subchoice);

                    switch(subchoice){
                        case 1:{
                            do{
                                system("cls");
                                Subtract_2_1_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 2:{
                            do{
                                system("cls");
                                Subtract_2_2_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 3:{
                            do{
                                system("cls");
                                Subtract_N_M_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 4:{
                            do{
                                system("cls");
                                Subtract_N_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 0:
                            break;
                        default:{
                            printf("Lựa chọn không hợp lệ!\n");
                            system("pause");
                            break;
                        }
                    }
                }while(subchoice != 0);
                break;
            }

            // Phép nhân
            case 3:{
                do{
                    system("cls");
                    printf("=======Phép toán nhân=======\n");
                    printf("1: Nhân 2 số có 1 chữ số\n");
                    printf("2: Nhân 2 số có 2 chữ số\n");
                    printf("3: Nhân N số có M chữ số\n");
                    printf("4: Nhân N số ngẫu nhiên\n");
                    printf("0: Về trang chủ\n");
                    printf("Mời bạn chọn: ");
                    scanf("%d", &subchoice);

                    switch(subchoice){
                        case 1:{
                            do{
                                system("cls");
                                Multiply_2_1_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 2:{
                            do{
                                system("cls");
                                Multiply_2_2_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 3:{
                            do{
                                system("cls");
                                Multiply_N_M_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 4:{
                            do{
                                system("cls");
                                Multiply_N_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 0:
                            break;
                        default:{
                            printf("Lựa chọn không hợp lệ!\n");
                            system("pause");
                            break;
                        }
                    }
                }while(subchoice != 0);
                break;
            }

            // Phép chia
            case 4:{
                do{
                    system("cls");
                    printf("=======Phép toán chia=======\n");
                    printf("1: Chia 2 số có 1 chữ số\n");
                    printf("2: Chia 2 số có 2 chữ số\n");
                    printf("3: Chia N số có M chữ số\n");
                    printf("4: Chia N số ngẫu nhiên\n");
                    printf("0: Về trang chủ\n");
                    printf("Mời bạn chọn: ");
                    scanf("%d", &subchoice);

                    switch(subchoice){
                        case 1:{
                            do{
                                system("cls");
                                Divide_2_1_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 2:{
                            do{
                                system("cls");
                                Divide_2_2_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 3:{
                            do{
                                system("cls");
                                Divide_N_M_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 4:{
                            do{
                                system("cls");
                                Divide_N_number();
                                printf("Bạn muốn chơi lại?\n");
                                printf("Enter để chơi lại\n");
                                printf("Ấn bất kỳ phím nào để quay lại\n");
                                printf("> ");
                                fflush(stdin);
                                scanf("%c", &again);
                            }while(again == '\n');
                            break;
                        }
                        case 0:
                            break;
                        default:{
                            printf("Lựa chọn không hợp lệ!\n");
                            system("pause");
                            break;
                        }
                    }
                }while(subchoice != 0);
                break;
            }

            default:{
                printf("Lựa chọn không hợp lệ!\n");
                system("pause");
                break;
            }
        }
    }
    return 0;
}
