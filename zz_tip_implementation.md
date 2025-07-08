# 💡 Mẹo Viết Code Hiệu Quả (Implementation Tips)

[How to Effectively Practice CP + Problem Solving Guide](https://codeforces.com/blog/entry/116371)
---

## ✅ 1. Kiểm tra nhanh xem có cách dễ hơn không

Trước khi bắt tay vào code, hãy dành vài chục giây để tự hỏi:

> 🔍 “Liệu mình có đang chọn cách implement quá rườm rà không?”  
> 🔍 “Có mẹo, trick hoặc cấu trúc nào giúp mình code ngắn hơn không?”

Một ý tưởng đơn giản hơn có thể **tiết kiệm rất nhiều thời gian debug** sau này.

---

## 🧠 2. Lên kế hoạch trước khi gõ từng dòng code

- Hãy hình dung code thành **nhiều đoạn nhỏ (chunk)**.
- Trước khi viết một đoạn:
  - Hiểu rõ vai trò của đoạn đó.
  - Biết dùng biến nào, xử lý gì.
- Nếu chưa rõ → **dừng lại suy nghĩ**, đừng vừa viết vừa đoán.

---

## ✍️ 3. Viết code ngắn gọn, dễ đọc, tránh lặp lại

- Tránh copy–paste rồi chỉnh sửa từng dòng — dễ lỗi và rối.
- Nếu thấy mình **viết lại cùng một ý nhiều lần**, nên:
  - Tách ra thành hàm phụ.
  - Dùng cấu trúc dữ liệu phù hợp hơn.
  - **Refactor** lại toàn bộ logic nếu cần.

---

## 🐞 4. Debug có chiến lược, không mò mẫm

- In ra **nhiều biến trung gian** để kiểm tra logic.
- Dùng **binary search trên luồng thực thi**:
  - Chèn `print` tại các điểm kiểm tra.
  - Xác định đoạn nào đầu ra bắt đầu sai → **thu hẹp lỗi**.

> ⚠️ Nếu đoạn code nào đó sai mà sửa mãi không xong:
> → **Ngưng chỉnh sửa vụn vặt** → Lập lại kế hoạch → Viết lại đoạn đó.

### 🔁 Các kỹ thuật debug thêm:
- **Mô phỏng test case bằng tay**, từng bước như máy tính.
- **Đọc lại từng dòng code**, kể cả những dòng bạn nghĩ “chắc chắn đúng”.

---

## 📝 5. Thêm chú thích ngắn gọn cho mỗi bài

Ghi một dòng comment ở đầu chương trình/hàm chính:

```cpp
// Ý tưởng chính: Dùng prefix sum + greedy để tìm đoạn con tối ưu
```

# Mục tiêu của việc Luyện tập

## Mục tiêu chính
Học được càng nhiều ý tưởng và khái niệm sâu sắc càng tốt trong thời gian ngắn nhất, đồng thời phát triển trực giác để biết khi nào và cách áp dụng chúng.

## Mục tiêu phụ
Bạn nên cảm thấy áp lực khi cố gắng nghĩ ra những ý tưởng mới - đây là điều tốt. Tuy nhiên, đừng nhầm lẫn điều này với việc hoang mang không biết phải làm gì.

Trạng thái lý tưởng là không ngừng tạo ra những hiểu biết mới một cách nhanh chóng - đây chính là những gì bạn cần trong thi đấu thực tế. Bạn cần quen với việc liên tục suy nghĩ những ý tưởng mới mà không bị "mắc kẹt" trong những suy nghĩ lặp đi lặp lại.

Tuy nhiên, khi hoàn toàn không biết cách tiếp cận một bài toán, bạn sẽ dễ mất tập trung và không học được gì. Vì vậy, hãy cố gắng giảm thiểu những tình huống này.