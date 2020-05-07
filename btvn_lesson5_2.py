'''================BTVN lesson 5==============='''
"======================Tuple======================"
'''
Bài 00: Viết chương trình sinh một tuple chứa các phần tử có các kiểu dữ liệu khác nhau.
    Sau đó, unpack các phần tử trong một tuple.
Bài 01: Viết chương trình chuyển một tuple sang thành list và ngược lại từ list sang tuple
Bài 02: Viết chương trình đảo ngược một tuple.
Bài 03: Viết chương trình đếm số lượng các phần tử trong một list đến khi gặp một phần tử kiểu tuple.
Bài 04: Cho 1 list chứa các tuple không rỗng.
    Viết chương trình sắp xếp list đó theo chiều tăng dần của phần tử cuối trong mỗi tuple.
    Ví dụ: [(2, 5), (4, 1), (0, 0)]  => [(0, 0), (4, 1), (2, 5)]
Bài 05: Viết chương trình tìm ra tuple có phần tử thứ 2 là nhỏ nhất từ một list chứa các tuple.
Bài 06: Viết chương trình in ra phần tử thứ 4 và phần tử thứ 4 từ cuối lên trong một tuple.
Bài 07: Viết chương trình kiểm tra 2 tuple có phần tử chung hay không.
Bài 08: Viết chương trình kiểm tra xem tất cả các phần tử trong tuple có giống nhau hay không.
Bài 09: Viết chương trình tính tổng và tìm giá trị lớn nhất trong tuple chứa các số thực.
Bài 10: Cho list sau: ["www.hust.edu.vn", "www.wikipedia.org", "www.asp.net", "www.amazon.com"]
    Viết chương trình để in ra hậu tố (vn, org, net, com) trong các tên miền website trong list trên.
Bài 11: Viết chương trình tìm từ dài nhất trong một câu nhập vào từ bàn phím.
'''
menu = {}
menu['0'] = 'Bài 00'
menu['1'] = 'Bài 01'
menu['2'] = 'Bài 02'
menu['3'] = 'Bài 03'
menu['4'] = 'Bài 04'
menu['5'] = 'Bài 05'
menu['6'] = 'Bài 06'
menu['7'] = 'Bài 07'
menu['8'] = 'Bài 08'
menu['9'] = 'Bài 09'
menu['10'] = 'Bài 10'
menu['11'] = 'Bài 11'
menu['12'] = 'Thoát'

while True:
    options = menu.keys()
    for k in options:
        print(k, [menu[k]])
    selection = input("Nhập lựa chọn của bạn: ")

    if selection == '0':
        tuple000 = 'kate',2000,['python', 'java'], 3-2j  #packing a tuple named tuple000
        print(tuple000)
        print(type(tuple000))

        x,y,z,t = tuple000     #unpacking a tuple name tuple000
        print(f"x = {x}, y = {y}, z = {z}, t = {t}")

    elif selection == '1':
        tuple000 = 'kate', 2000, ['python', 'java'], 3 - 2j

        list01 = list(tuple000)        #Chuyển tuple thành list
        print(type(list01))
        print(list01)

        tuple01 = tuple(list01)      #Chuyển list thành tuple
        print(type(tuple01))
        print(tuple01)

    elif selection == '2':
        tuple000 = 'kate', 2000, ['python', 'java'], 3 - 2j
        print(tuple000[::-1])

    elif selection == '3':
        list03 = list(input("Nhập list: ")) #[1,2,3,4,('a','java',9), "string"]
        dem = 0
        for i in list03:
            if isinstance(i, tuple): #isinstance check object in type tuple or not?
                break
            dem += 1
        print(dem)

    elif selection == '4':
        def takeLast(element):
            return element[-1]
        list4 = [(2, 5), (4, 1), (0, 0), (3,3), (1,2), (6,6), (7,7,7), (8,8,8), (1,5,9)]
        list4.sort(key = takeLast)
        print(list4)

    elif selection == '5':
        def takeSecond(element):
            return element[1]
        list5 = [(2, 5), (4, 1), (0, 0), (3,3), (1,2), (6,-2), (7,-5,7), (8,15,8), (1,5,9)]
        list5.sort(key = takeSecond)
        print(list5)

    elif selection == '6':
        tuple6 = (1,2,3,4,5,6,7,8,9,0)
        print(tuple6[3])
        print(tuple6[-4])

    elif selection == '7':
        tup71 = (1,2,3,'a','o','python')
        tup72 = (3,'o','python','java','kate')
        list7 = []
        for i in range(len(tup71)-1):
            if tup71[i] in tup72:
                list7.append(tup71[i])
        print("Các phần tử chung cả 2 tuple là {}: ".format(list7))

    # elif selection =='8':

    elif selection == '9':
        tuple9 = tuple(input("Nhập vào tuple chứa các số thực: "))  #(1,2,3,4,5,6,7,8,9,-5,-4)
        print("Sum of tuple9 is: ", sum(tuple9))
        print("Max of tuple9 is: ", max(tuple9))

    #elif selection =='10':

    elif selection == '11':
        items = [x for x in input("Nhập một chuỗi: ").split(',')]
        items.sort()
        print(','.join((items)))
        print(items[len(items) - 1], end=" ")

    elif selection == '12':
        print("===========Thoát!==========")
        break

    else:
        print("+++++++Số bạn nhập không hợp lệ.Mời bạn chọn lại!+++++++")






