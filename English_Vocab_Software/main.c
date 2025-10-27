#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <shellapi.h>
#include <time.h>

// Cấu trúc của một từ vựng
typedef struct {
    char tu[50];
    char nghia[100];
    char loai[10];
} Tuvung;

// Cấu trúc của một câu hỏi
typedef struct {
    char Eng[100];
    char Vie[100];
} Word;

// Khai báo prototype
void Menu_Chinh();
void Nhap_tu_vung_moi();
void Chuan_hoa_chuoi(char str[]);
void Ghi_vao_file(Tuvung tv);
void Ghi_vao_file_data(Tuvung tv);
void Them_1_tu(Tuvung *tv, const char *Loai_tu);
Word* Doc_file_data(const char* filename, int* count);
void Tao_Quiz(Word* list, int n);
void On_tu_vung();
void Cai_dat();

// Chuẩn hóa chuỗi: Chữ đầu viết hoa, các chữ còn lại viết thường
void Chuan_hoa_chuoi(char str[]) {
    int len = strlen(str);
    int i = 0;
    while (str[i] == ' ' && str[i] != '\0') i++;
    if (str[i] != '\0') {
        str[i] = toupper(str[i]);
        for (int j = i + 1; j < len; j++) {
            str[j] = tolower(str[j]);
        }
    }
}

// Ghi từ vựng vào file tuvung.txt
void Ghi_vao_file(Tuvung tv) {
    FILE *f = fopen("tuvung.txt", "a");
    if (!f) {
        printf("Lỗi: Không mở được file tuvung.txt\n");
        return;
    }
    fprintf(f, "%s;%s;%s\n", tv.tu, tv.nghia, tv.loai);
    fclose(f);
}

// Ghi từ vựng vào file data.txt
void Ghi_vao_file_data(Tuvung tv) {
    FILE *f = fopen("data.txt", "a");
    if (!f) {
        printf("Lỗi: Không mở được file data.txt\n");
        return;
    }
    fprintf(f, "%s;%s\n", tv.tu, tv.nghia);
    fclose(f);
}

// Nhập một từ vựng mới
void Them_1_tu(Tuvung *tv, const char *Loai_tu) {
    printf("Nhập từ vựng tiếng Anh: ");
    fgets(tv->tu, sizeof(tv->tu), stdin);
    tv->tu[strcspn(tv->tu, "\n")] = '\0';
    Chuan_hoa_chuoi(tv->tu);

    printf("Nhập nghĩa tiếng Việt: ");
    fgets(tv->nghia, sizeof(tv->nghia), stdin);
    tv->nghia[strcspn(tv->nghia, "\n")] = '\0';
    Chuan_hoa_chuoi(tv->nghia);

    if (Loai_tu != NULL) {
        strcpy(tv->loai, Loai_tu);
    } else {
        do {
            printf("Nhập từ loại của %s (VD: V, N, Adj, Adv): ", tv->tu);
            fgets(tv->loai, sizeof(tv->loai), stdin);
            tv->loai[strcspn(tv->loai, "\n")] = '\0';
            Chuan_hoa_chuoi(tv->loai);
            if (strcmp(tv->loai, "V") == 0 || strcmp(tv->loai, "N") == 0 ||
                strcmp(tv->loai, "Adj") == 0 || strcmp(tv->loai, "Adv") == 0) {
                break;
            }
            printf("Lỗi: Từ loại không hợp lệ! Vui lòng nhập lại.\n");
        } while (1);
    }
    Ghi_vao_file(*tv);
    Ghi_vao_file_data(*tv);
    printf("Đã lưu từ vựng: %s thành công!\n", tv->tu);
    Sleep(200); // Đợi 1 giây trước khi xóa màn hình
    system("cls");
}

// Nhập từ vựng mới và gia đình từ
void Nhap_tu_vung_moi() {
    int choice;
    char Y_N;
    do {
        Tuvung tv;
        printf("-----------Nhập từ mới----------\n");
        Them_1_tu(&tv, NULL);
        
        if (strcmp(tv.loai, "V") == 0 || strcmp(tv.loai, "N") == 0 ||
            strcmp(tv.loai, "Adj") == 0 || strcmp(tv.loai, "Adv") == 0) {
            printf("Bạn có muốn nhập tiếp các từ liên quan (Gia đình từ) của %s không? (y/n): ", tv.tu);
            scanf("%c", &Y_N);
            getchar();
            system("cls");
            if (Y_N == 'y' || Y_N == 'Y') {
                char *thu_tu_V[] = {"N", "Adj", "Adv"};
                char *thu_tu_N[] = {"V", "Adj", "Adv"};
                char *thu_tu_Adj[] = {"V", "N", "Adv"};
                char *thu_tu_Adv[] = {"V", "N", "Adj"};
                char **thu_tu;

                if (strcmp(tv.loai, "V") == 0) thu_tu = thu_tu_V;
                else if (strcmp(tv.loai, "N") == 0) thu_tu = thu_tu_N;
                else if (strcmp(tv.loai, "Adj") == 0) thu_tu = thu_tu_Adj;
                else thu_tu = thu_tu_Adv;

                for (int i = 0; i < 3; i++) {
                    printf("Nhập %s của %s (0: Dừng, Enter để bỏ qua): ", thu_tu[i], tv.tu);
                    char temp_tu[50];
                    fgets(temp_tu, sizeof(temp_tu), stdin);
                    temp_tu[strcspn(temp_tu, "\n")] = '\0';
                    if (strcmp(temp_tu, "0") == 0) break;
                    if (strlen(temp_tu) == 0) continue;

                    strcpy(tv.tu, temp_tu);
                    Chuan_hoa_chuoi(tv.tu);

                    printf("Nhập nghĩa tiếng Việt của từ %s (Enter để bỏ qua): ", tv.tu);
                    char temp_nghia[100];
                    fgets(temp_nghia, sizeof(temp_nghia), stdin);
                    temp_nghia[strcspn(temp_nghia, "\n")] = '\0';
                    strcpy(tv.nghia, strlen(temp_nghia) > 0 ? temp_nghia : "");
                    Chuan_hoa_chuoi(tv.nghia);

                    strcpy(tv.loai, thu_tu[i]);
                    Ghi_vao_file(tv);
                    Ghi_vao_file_data(tv);
                    printf("Đã lưu từ '%s' (%s) vào file tuvung.txt\n", tv.tu, tv.loai);
                    Sleep(200);
                    system("cls");
                }
            }
        }

        printf("-----Menu tính năng thêm từ vựng mới-----\n");
        printf("1: Thêm từ mới\n");
        printf("2: Mở file từ vựng bản thân đã lưu\n");
        printf("3: Về Menu chức năng chính\n");
        printf("0: Thoát chương trình\n");
        printf("Mời bạn chọn (VD: 1): ");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice) {
            case 1:
                continue;
            case 2:
                ShellExecute(NULL, "open", "tuvung.txt", NULL, NULL, SW_MAXIMIZE);
                break;
            case 3:
                Menu_Chinh();
                break;
            case 0:
                printf("Đã thoát\n");
                exit(0);
            default:
                printf("Lựa chọn không hợp lệ!\n");
                Sleep(200);
                system("cls");
        }
    } while (choice != 0);
}

// Đọc file data.txt để tạo danh sách từ vựng
Word* Doc_file_data(const char* filename, int* count) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Lỗi: Không mở được file %s!\n", filename);
        return NULL;
    }
    Word* list = NULL;
    *count = 0;
    char line[200];

    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = '\0';
        char* token = strtok(line, ";");
        if (!token) continue;

        list = realloc(list, (*count + 1) * sizeof(Word));
        strcpy(list[*count].Eng, token);

        token = strtok(NULL, ";");
        strcpy(list[*count].Vie, token ? token : "");
        (*count)++;
    }
    fclose(f);
    return list;
}

// Tạo câu hỏi trắc nghiệm
void Tao_Quiz(Word* list, int n) {
    if (n < 4) {
        printf("Cần ít nhất 4 từ để tạo quiz!\n");
        return;
    }
    int correct = rand() % n;
    int wrong1 = rand() % n;
    int wrong2 = rand() % n;
    int wrong3 = rand() % n;

    while (wrong1 == correct) wrong1 = rand() % n;
    while (wrong2 == correct || wrong2 == wrong1) wrong2 = rand() % n;
    while (wrong3 == correct || wrong3 == wrong1 || wrong3 == wrong2) wrong3 = rand() % n;

    int options[4] = {correct, wrong1, wrong2, wrong3};
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tmp = options[i];
        options[i] = options[j];
        options[j] = tmp;
    }

    printf("Từ tiếng Anh: %s\n", list[correct].Eng);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, list[options[i]].Vie);
    }

    int ans;
    printf("Chọn (1-4): ");
    scanf("%d", &ans);
    getchar();
    if (ans >= 1 && ans <= 4 && options[ans - 1] == correct) {
        printf("Đúng! %s = %s\n", list[correct].Eng, list[correct].Vie);
    } else {
        printf("Sai! Đáp án đúng: %s = %s\n", list[correct].Eng, list[correct].Vie);
    }
    Sleep(200);
    system("cls");
}

// Ôn tập từ vựng
void On_tu_vung() {
    int choice;
    srand(time(NULL)); // Khởi tạo seed cho rand()
    do {
        printf("--------------Ôn tập từ vựng-------------\n");
        printf("1: Ôn tập trắc nghiệm các từ đã lưu\n");
        printf("2: Ôn tập các từ có sẵn trên hệ thống\n");
        printf("0: Về Menu chính\n");
        printf("Mời bạn chọn (VD: 1): ");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice) {
            case 0:
                Menu_Chinh();
                break;
            case 1: {
                int count;
                Word* list = Doc_file_data("tuvung.txt", &count);
                if (!list || count == 0) {
                    printf("Chưa có dữ liệu để ôn tập!\n");
                    printf("Hãy thêm ít nhất 4 từ.\n");
                    free(list);
                    Sleep(200);
                    system("cls");
                    break;
                }
                if (count < 4) {
                    printf("Cần ít nhất 4 từ để tạo quiz!\n");
                    free(list);
                    Sleep(200);
                    system("cls");
                    break;
                }
                do {
                    Tao_Quiz(list, count);
                    printf("Bạn có muốn tiếp tục ôn tập? (y/n): ");
                    char cont;
                    scanf("%c", &cont);
                    getchar();
                    system("cls");
                    if (cont != 'y' && cont != 'Y') break;
                } while (1);
                free(list);
                break;
            }
            case 2: {
                int count;
                Word* list = Doc_file_data("data.txt", &count);
                if (!list || count == 0) {
                    printf("Chưa có dữ liệu để ôn tập!\n");
                    printf("Hãy đảm bảo file data.txt có ít nhất 4 từ.\n");
                    free(list);
                    Sleep(200);
                    system("cls");
                    break;
                }
                if (count < 4) {
                    printf("Cần ít nhất 4 từ để tạo quiz!\n");
                    free(list);
                    Sleep(200);
                    system("cls");
                    break;
                }
                do {
                    Tao_Quiz(list, count);
                    printf("Bạn có muốn tiếp tục ôn tập? (y/n): ");
                    char cont;
                    scanf("%c", &cont);
                    getchar();
                    system("cls");
                    if (cont != 'y' && cont != 'Y') break;
                } while (1);
                free(list);
                break;
            }
            default:
                printf("Lựa chọn không hợp lệ!\n");
                Sleep(200);
                system("cls");
        }
    } while (choice != 0);
}

// Menu chính
void Menu_Chinh() {
    int chon, temp, temp1;
    do {
        printf("----------Menu tính năng chính-----------\n");
        printf("1: Thêm từ vựng mới\n");
        printf("2: Ôn tập từ vựng\n");
        printf("3: Mở file từ vựng bản thân đã lưu\n");
        printf("4: Mở file dữ liệu hệ thống\n");
        printf("5: Cài đặt\n");
        printf("0: Thoát ứng dụng\n");
        printf("Mời bạn chọn (VD: 1): ");
        scanf("%d", &chon);
        getchar();
        system("cls");
        switch (chon) {
            case 0:
                printf("Đã thoát ứng dụng\n");
                exit(0);
            case 1:
                Nhap_tu_vung_moi();
                break;
            case 2:
                On_tu_vung();
                break;
            case 3:
                ShellExecute(NULL, "open", "tuvung.txt", NULL, NULL, SW_MAXIMIZE);
                break;
            case 4:
                printf("Bạn có chắc chắn muốn mở file dữ liệu hệ thống không?\n");
                printf("y: Có\n");
                printf("n: Không\n");
                printf("Mời bạn chọn: ");
                scanf("%c", &temp);
                getchar();
                system("cls");
                switch(temp){
                    case 'y':
                        ShellExecute(NULL, "open", "data.txt", NULL, NULL, SW_MAXIMIZE);
                        printf("Đã mở file dữ liệu hệ thống.\n");
                        Sleep(200);
                        system("cls");
                    case 'n':
                        printf("Hủy mở file dữ liệu hệ thống.\n");
                        Sleep(200);
                        system("cls");
                    default:    
                        printf("Lựa chọn không hợp lệ!\n");
                        Sleep(200);
                        system("cls");
                }
            case 5:
                printf("Chế độ cài đặt: \n");
                printf("Vui lòng xem hướng dẫn sử dụng để sài phần mềm hiệu quả\n");
                printf("1: Xem hướng dẫn sử dụng, khắc phục lỗi\n");
                printf("2: Giải thích tính năng\n");
                printf("3: Xem mô tả phần mềm\n");
                printf("0: Về menu chính\n");
                printf("Mời chọn: \n");
                scanf("%d", &temp1);
                switch(temp1){
                    case 1:
                        ShellExecute(NULL, "open", "Huong_dan_su_dung.docx", NULL, NULL, SW_MAXIMIZE);
                        break;
                    case 2:
                        ShellExecute(NULL, "open", "Giai_thich.docx", NULL, NULL, SW_MAXIMIZE);
                        break;
                    case 3:
                        ShellExecute(NULL, "open", "README_Vietnamese.md", NULL, NULL, SW_MAXIMIZE);
                        break;
                    case 0:
                        system("cls");
                        Menu_Chinh();
                        break;
                    default:
                        printf("Lựa chọn không hợp lệ");
                        Sleep(200);
                        system("cls");
                }
            default:
                printf("Lựa chọn không hợp lệ!\n");
                Sleep(200);
                system("cls");
        }
    } while (1);
}

int main() {
    SetConsoleOutputCP(65001); // Hỗ trợ tiếng Việt
    SetConsoleCP(65001);
    printf("-------------EnglishSaveVocab------------\n");
    Menu_Chinh();
    return 0;
}
