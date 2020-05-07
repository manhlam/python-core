'''Bài 00: Viết chương trình tính tích các phần tử trong một dict
Bài 01: Viết chương trình tìm giá trị lớn nhất và giá trị nhỏ nhất của trường value trong một dict
Bài 02: Viết chương trình sắp xếp các phần tử của dict theo chiều tăng dần của key
Bài 03: Viết chương trình lấy các các giá trị không trùng lặp từ dict
Bài 04: Viết chương trình tìm ra 3 phần tử có key lớn nhất trong dict
Bài 05: Viết chương trình tạo ra dict với lớn hơn 3 phần tử, value của mỗi phần tử là một list có lớn hơn 5 phần tử.
        Truy cập và in ra phần tử thứ 5 trong phần value của mỗi phần tử trong dict
Bài 06: Viết chương trình lấy ra các phần tử key-value xuất hiện trong cả 2 dict
Bài 07: Viết chương trình tạo dict mới bằng cách trích xuất dữ liệu từ dict ban đầu theo tập các key cho trước
Ví dụ:
    dict ban đầu: sampleDict = {"name": "Kelly", "age":25, "salary": 8000, "city": "New york"}
    keys = ["name", "salary"]
    Output: {'name': 'Kelly', 'salary': 8000}
Bài 08: Viết chương trình lấy ra top 3 phần tử có giá trị lớn nhất từ dict
Bài 09: Viết hàm đếm số lần xuất hiện các ký tự trong một String
Ví dụ:
    Input: ‘Stringings’
    Output: {‘S’: 1, ‘t’: 1, ‘r’: 1, ’i’: 2,  ‘n’: 2, ‘g’: 2, ‘s’: 1}
Bài 10: Viết hàm đếm số lần xuất hiện các từ đơn trong một đoạn văn bản
Bài 11: Viết chương trình để sinh ra dict mới từ list các dict có dạng như trong ví dụ:
Ví dụ:
    Input: [{'item': 'item1', 'amount': 400}, {'item': 'item2', 'amount': 300}, {'item': 'item1', 'amount': 750}]
    Output: {'item1': 1150, 'item2': 300}
'''
print("==========BTVN Lesson 06==========")
menu = {}

menu ['0'] = 'Bai 00'
menu ['1'] = 'Bai 01'
menu ['2'] = 'Bai 02'
menu ['3'] = 'Bai 03'
menu ['4'] = 'Bai 04'
menu ['5'] = 'Bai 05'
menu ['6'] = 'Bai 06'
menu ['7'] = 'Bai 07'
menu ['8'] = 'Bai 08'
menu ['9'] = 'Bai 09'
menu ['10'] = 'Bai 10'
menu ['11'] = 'Bai 11'
menu ['12'] = 'Thoát'

while True:
    options = menu.keys()
    for k in options:
        print(k, [menu[k]])
    selection = input("Nhập lựa chọn của bạn: ")

    if selection == '0':
        print("Bài 00: Viết chương trình tính tích các phần tử trong một dict")
        dict0 = {1,2,3,4,5,6,-3}
        tich = 1
        for i in dict0:
            tich *= i
        print("dict0: ",dict0)
        print("Tích các phần tử của dict: ",tich)

    elif selection == '1':
        print("Bài 01: Viết chương trình tìm giá trị lớn nhất và giá trị nhỏ nhất của trường value trong một dict")
        dict1 = {
            'first' : 1,
            'second' : 2,
            'third' : 3,
            'zero' : 0,
            'negative' : -5
        }
        print("dict1: ",dict1)
        print(max(dict1.values()))
        print(min(dict1.values()))


    elif selection == '2':
        print("Bài 02: Viết chương trình sắp xếp các phần tử của dict theo chiều tăng dần của key")
        dict2 = {
            '1st' : 1,
            'python' : 'core',
            'java' : 'core',
            'c/c++' : 'online',
            'lam' : 'k63'
        }
        print("dict2: ",dict2)
        print(sorted(dict2.keys()))   #sắp xếp các key theo thứ tự alpha B

    elif selection == '3':
        print("Bài 03: Viết chương trình lấy các các giá trị không trùng lặp từ dict")
        dict3 = {
            '1st' : 1,
            'python' : 'core',
            'java' : 'core',
            'c/c++' : 'online',
            'lam' : 'k63'
        }
        print("dict3: ",dict3)
        print(set(dict3.values()))  #set in ra gía trị không trùng lặp

    elif selection == '4':
        print("Bài 04: Viết chương trình tìm ra 3 phần tử có key lớn nhất trong dict")
        dict4 = {
            9: 'Bai09',
            7: 'Bai07',
            3: 'Bai03',
            0: 'Bai00',
            11: 'Bai11',
            12: 'Thoat',
            2: 'Bai02'
        }
        print("dict4: ",dict4)
        x = sorted(dict4.items(), reverse=True)
        print(x)
        print(x[0], x[1], x[2])

    elif selection == '5':
        print("Bài 05: Viết chương trình tạo ra dict với lớn hơn 3 phần tử, value của mỗi phần tử là một list có lớn hơn 5 phần tử."
            "\nTruy cập và in ra phần tử thứ 5 trong phần value của mỗi phần tử trong dict")
        print("CHƯA LÀM ĐƯỢC")


    elif selection == '6':
        print("06: Viết chương trình lấy ra các phần tử key-value xuất hiện trong cả 2 dict")
        dict61 = {
            9: 'Bai09',
            7: 'Bai07',
            3: 'Bai03',
            0: 'Bai00',
            11: 'Bai11',
            12: 'Thoat',
            2: 'Bai02'
        }
        dict62 = {
            9: 'Bai09',
            6: 'Bai06',
            3: 'Bai03',
            0: 'Bai00',
            13: 'None-exist',
            12: 'Thoat',
            4: 'Bai04'
        }
        print("dict61: ", dict61)
        print("dict62: ", dict62)
        for i in dict61:
            if i in dict62:
                print(i, ": ", dict61[i])

    elif selection == '7':
        print("Bài 07: Viết chương trình tạo dict mới bằng cách trích xuất dữ liệu từ dict ban đầu theo tập các key cho trước")
        dict7 = {
            9: 'Bai09',
            6: 'Bai06',
            3: 'Bai03',
            0: 'Bai00',
            13: 'None-exist',
            12: 'Thoat',
            4: 'Bai04'
        }
        print("dict7: ",dict7)
        key = dict7.keys()
        value = 'dictionary'  # gán key của dict 7 vào value dictionary

        # key = 'a'
        # value = dict7.values()   #Gán key 'a' cho cả 1 dict_value

        # print(dict7.values())
        # print(dict7.keys())

        print(dict.fromkeys(key, value))

    elif selection == '8':
        print("Bài 08: Viết chương trình lấy ra top 3 phần tử có giá trị lớn nhất từ dict")
        dict8 = {
            'a': 1,
            'b': 3,
            'c': 19,
            'd': 2000,
            'e': -5,
            'f': 18.99999,
            'g': 30
        }
        print("dict8: ",dict8)
        x = sorted(dict8.values(), reverse=True)
        print(x)
        print("Ba giá trị lớn nhất:", x[0], x[1], x[2])


    elif selection == '9':
        print("Bài 09: Viết hàm đếm số lần xuất hiện các ký tự trong một String")
        s = str(input("input a string: "))
        count = {}
        for i in s:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        print(s)
        print("Số lần xuất hiện của ký tự trong string: ",count)

    elif selection == '10':
        print("Bài 10: Viết hàm đếm số lần xuất hiện các từ đơn trong một đoạn văn bản")
        s = (input("input a string: ")).split(" ")
        count = {}
        for i in s:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        print("s = ",s)
        print("Số lần xuất hiện các từ đơn trong đoạn văn bản: ",count)

    elif selection == '11':
        print("Bài 11: Viết chương trình để sinh ra dict mới từ list các dict có dạng như trong ví dụ:")
        print("CHƯA LÀM ĐƯỢC")


    elif selection == '12':
        print("===========Thoát!==========")
        break

    else:
        print("+++++++Số bạn nhập không hợp lệ.Mời bạn chọn lại!+++++++")




