menu = {}

menu['1'] = "Các phương thức với set:"
menu['2'] = "Các phương thức với set và list:"
menu['0'] = "Thoát!"

while True:
    options = menu.keys()
    for k in options:
        print(k, menu[k])
    selection = input("Nhập lựa chọn của ban: ")

    if selection == '1':
        set0 = {0,1,2,3,4,5,6,'Hello','goodbye','python'}
        set01 = {2,4,6,'goodmorning','pycharm'}
        set011 = {}

        set1 = set0.copy()     #copy và trả lại 1 bản sao của set0
        print(set1)

        set2 = set1.clear()    #Xóa set1 trở thành set rỗng
        print(set2)

        set3 = set1.add('java')    #thêm 1 phần tử vào set1
        print(set3)

        set4 = set0.difference(set01)     #Phần bù của set01 và set1
        print(set4)

        set5 = set1.difference_update(set01)    #Cập nhật lại set bằng các giá trị phần bù của set với set01
        print(set5)

        set6 = set01.discard('pycharm')     #Xóa phần tử trong set, nếu khong có trong set thì không ảnh hưởng
        print(set6)

        set7 = set1.intersection(set01)    #trả lại giao của set1 và set01
        print(set7)

        set8 = set1.intersection_update(set01)  #Cập nhạt set1 bằng giá trị giao của nó với set01
        print(set8)

        set9 = set1.isdisjoint(set01)   # trả lại true nếu set1 và set 01 không giao nhau
        print(set9)

        set10 = set1.issubset(set01)   #set1 la con của set01
        print(set10)

        set11 = set1.issuperset(set01)   #set1 có chứa set01
        print(set11)

        #set12 = set1.pop()    #xóa bỏ phàn tử trong set và trả lại; error nếu là rỗng
        #print(set12)

        set13 = set01.remove(6)     #xóa element khỏi set, nếu set rỗng return error
        print(set13)

        set14 = set1.symmetric_difference(set01)    #trả lại phàn bù đối xứng
        print(set14)

        set15 = set1.symmetric_difference_update(set01)    #update lại giá trị của set bằng phần bù của set1 và set01
        print(set15)

        set16 = set1.union(set01)      #trả lại hợp giữa 2 hay nhiều set
        print(set16)

        set17 = set1.update(set01)   #update set bằng hợp giữa 2 hay nhiều set
        print(set17)

    elif selection == '2':
        print("=========Thực hiện phương thức với set (và list)===========")
        set02 = {1,2,3,4,5,6,'Hello','a','kata','kumite'}
        set03 = {}

        print(all(set02))
        print(all(set03))     #trả về true nếu tất cả các phần tử trong set là rue hoặc rộng

        print(any(set02))
        print(any(set03))     #trả về giá trị true nếu bất kì phần tử nào true, nếu rỗng trả về false

        print(enumerate(set02))  #trả về kiểu liệt kê, bao gồm chỉ số và giá tị tương ứng

        print(len(set02))
        print(len(set03))

        #print(max(set02))
        #print(min(set02))

        #print(sorted(set02, key = len, reverse = True))

        #print(sum(set02))    #trả lại tổng các phần tử

    elif selection == '0':
        print("Thoát")
        break

    else:
        print("Mời bạn chọn lại!")
