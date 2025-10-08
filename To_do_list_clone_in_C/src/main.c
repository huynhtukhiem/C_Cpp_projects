#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // để viết tiếng việt
#define MAX 100

// ====== Cấu trúc của một Task ====== //
typedef struct Task{
    char name[MAX];      // Nội dung công việc
    char deadline[MAX];  // Thời hạn
    char note[MAX];      // Ghi chú
    struct Task* next;   // Con trỏ liên kết
}Task;

// ====== Lưu một task vào file CSV ====== //
void Save_task(Task* task, const char* file_name){
    FILE *f = fopen(file_name, "a"); // Mở ở chế độ ghi chèn
    if (f == NULL) {
        printf("Không mở được file %s!\n", file_name);
        exit(1);
    }

    int result = fprintf(f, "%s,%s,%s\n", task->name, task->deadline, task->note);
    if (result < 0)
        printf("Lỗi khi ghi vào file!\n");
    else
        printf("Đã ghi công việc vào file thành công!\n");

    fclose(f); // Đóng file để tránh rò rỉ bộ nhớ
}

// ====== Tạo một task mới ====== //
Task* Create_task(char name[], char deadline[], char note[]){
    Task* New_task = (Task*)malloc(sizeof(Task)); // Cấp phát vùng nhớ cho task
    if (New_task == NULL) {
        printf("Không đủ bộ nhớ!\n");
        exit(1);
    }
    strcpy(New_task->name, name);
    strcpy(New_task->deadline, deadline);
    strcpy(New_task->note, note);
    New_task->next = NULL;
    return New_task;
}

// ====== Thêm task vào danh sách ====== //
Task* Append_task(Task** head, char name[], char deadline[], char note[]){
    Task* New_task = Create_task(name, deadline, note);
    if(*head == NULL){
        *head = New_task;
        return New_task;
    }
    Task* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = New_task;
    return New_task;
}

// ====== In danh sách công việc ====== //
void Print_task(Task* head){
    if(head == NULL){
        printf("Danh sách hiện tại rỗng!\n");
        return;
    }
    printf("===== DANH SÁCH CÔNG VIỆC =====\n");
    Task* temp = head;
    int i = 1;
    while(temp != NULL){
        printf("%d. %s | Deadline: %s | Ghi chú: %s\n",
               i, temp->name, temp->deadline, temp->note);
        temp = temp->next;
        i++;
    }
    printf("================================\n");
}

// ====== Đọc task từ file CSV ====== //
void Read_task_from_file(Task** head, const char* file_name){
    FILE *f = fopen(file_name, "r");
    if(f == NULL){
        printf("File %s chưa tồn tại hoặc trống.\n", file_name);
        return;
    }

    char line[MAX * 3];
    while(fgets(line, sizeof(line), f)){
        char name[MAX], deadline[MAX], note[MAX];
        if (sscanf(line, "%[^,],%[^,],%[^\n]", name, deadline, note) == 3){ // Này là dùng để lấy cái task từ file ra
            Append_task(head, name, deadline, note);
        }
    }
    fclose(f);
}

// ====== Hàm chính ====== //
int main(){
    SetConsoleOutputCP(65001); // Hiển thị tiếng Việt trong console
    Task* todo = NULL; // Ban đầu cho bằng NULL vì chưa có công việc nào
    char name[MAX], deadline[MAX], note[MAX];
    int choice;
    const char* FILE_NAME = "todo.csv";

    while(1){
        system("cls");
        printf("===== TO-DO LIST CLONE =====\n");
        printf("1. Thêm công việc\n");
        printf("2. Hiển thị danh sách công việc\n");
        printf("0. Thoát chương trình\n");
        printf("=============================\n");
        printf("Chọn: ");
        scanf("%d", &choice);
        getchar(); // bỏ ký tự '\n'

        if(choice == 0){
            printf("Tạm biệt!\n");
            break;
        }

        else if(choice == 1){
            system("cls");
            printf("Nhập nội dung công việc: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Nhập thời hạn (deadline): ");
            fgets(deadline, sizeof(deadline), stdin);
            deadline[strcspn(deadline, "\n")] = '\0';

            printf("Nhập ghi chú (nếu có): ");
            fgets(note, sizeof(note), stdin);
            note[strcspn(note, "\n")] = '\0';

            Task* new_task = Append_task(&todo, name, deadline, note);
            Save_task(new_task, FILE_NAME);

            printf("Đã lưu công việc thành công!\n");
            system("pause");
        }

        else if(choice == 2){
            system("cls");
            Task* file_list = NULL;
            Read_task_from_file(&file_list, FILE_NAME);
            Print_task(file_list);
            system("pause");
        }

        else{
            printf("Lựa chọn không hợp lệ, vui lòng nhập lại!\n");
        }
    }

    return 0;
}
