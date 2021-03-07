# Observe-process-management
# 觀察瀏覽器對thread group的管理
## 各檔案簡介
### get_thread_m.c
輸入一pid後，回傳tgid跟該pid的tgid一樣的process數  
也就是在同一個thread group的process數  
使用**pid_task**及**find_vpid**來尋找process descriptor  
再找出裡面的tgid和其他process做比較  
### thread.cpp
使用上面的system call在終端機上  
## 觀察結果
### Firefox
輸入由ps查詢到的pid
1.	一個分頁時：process 數量：1  
 ![image](https://user-images.githubusercontent.com/79785416/110228119-98e5ea00-7f39-11eb-8981-80ed896be176.png)
2.	三個分頁時：process數量：1  
 ![image](https://user-images.githubusercontent.com/79785416/110228128-a0a58e80-7f39-11eb-8031-03799fc9754b.png)
### Chromium  
1.	剛開啟時：process 數量：5 各自在不同thread group  
 ![image](https://user-images.githubusercontent.com/79785416/110228135-ae5b1400-7f39-11eb-9496-f7c961cc17fa.png)
2.	使用一個分頁時：process數量：6 各自在不同thread group  
 ![image](https://user-images.githubusercontent.com/79785416/110228140-b2873180-7f39-11eb-8f12-39cbecd6b860.png)
3.	使用兩個分頁時：process數量：6 各自在不同thread group  
 ![image](https://user-images.githubusercontent.com/79785416/110228141-b7e47c00-7f39-11eb-834f-d271a59dae89.png)
4.	使用三個分頁時：process數量：7 各自在不同thread group  
 ![image](https://user-images.githubusercontent.com/79785416/110228142-ba46d600-7f39-11eb-8c09-94744fdf0b32.png)
