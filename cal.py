import os
import numpy as np
import matplotlib.pyplot as plt

# 设置目标对角线长度的范围列表，从 1 到 200 像素，增量为 10 像素
diagonal_ranges = np.arange(1, 201, 10)

# 定义统计变量列表，初始值均为 0
range_counts = [0] * len(diagonal_ranges)

# 图像的宽度和高度
image_width = 880  # 图像宽度（像素）
image_height = 880  # 图像高度（像素）

# 遍历数据集中所有注释文件
data_dir = 'D:\\code\\python\\label\\data999 - 副本\\labels'  # 替换为数据集路径
for filename in os.listdir(data_dir):
    if filename.endswith('.txt') and filename.startswith('p'):
        # 打开注释文件
        filepath = os.path.join(data_dir, filename)
        with open(filepath, 'r') as f:
            for line in f:
                # 解析目标数据
                parts = line.strip().split()
                # class_id = int(parts[0])  # 目标类别（可以根据需要使用）
                x_center = float(parts[1])
                y_center = float(parts[2])
                width = float(parts[3])
                height = float(parts[4])

                # 计算目标对角线长度（相对值）
                diagonal_length_relative = np.sqrt(width ** 2 + height ** 2)

                # 将对角线长度相对值转换为像素长度
                diagonal_length_in_pixels = diagonal_length_relative * np.sqrt(image_width ** 2 + image_height ** 2)

                # 将对角线长度与范围列表进行比较，并增加对应范围的计数
                for i, range_limit in enumerate(diagonal_ranges):
                    if diagonal_length_in_pixels < range_limit:
                        range_counts[i] += 1
                        break

# 将每种数量乘以 100
range_counts = [count * 100 for count in range_counts]

# 打印统计结果
print("目标对角线长度的像素长度分布（乘以 100 后）:")
for i, range_limit in enumerate(diagonal_ranges):
    if i == 0:
        print(f'< {range_limit}: {range_counts[i]}')
    else:
        print(f'{diagonal_ranges[i - 1]} - {range_limit}: {range_counts[i]}')

# 可视化目标对角线长度的像素长度分布
plt.bar(diagonal_ranges, range_counts, width=10)
plt.xlabel('对角线长度 (像素)')
plt.ylabel('数量 (乘以 100)')
plt.title('目标对角线长度的像素长度分布')
plt.show()
