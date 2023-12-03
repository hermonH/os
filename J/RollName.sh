filename="example.txt"

display_file() 
{
    echo "Student Information:"
    sort -k1,1n "$filename" #resistricts sorting till 1st column of fields only
}

display_student() 
{
    echo "Enter roll number :"
    read roll_no
    grep -w "$roll_no" "$filename"
}

delete_student() 
{
    echo "Enter roll number :"
    read roll_no
    sed -i "/^$roll_no /d" "$filename"
}

add_student() 
{
    echo "Enter roll number, name and city :"
    read roll_no name city
    echo "$roll_no $name $city" >> "$filename"
}

update_student() 
{
    echo "Enter roll number, name and city :"
    read roll_no name city
    sed -i "/^$roll_no /s/[^ ]* [^ ]* [^ ]*/$roll_no $name $city/" "$filename"
}

while true; 
do
    echo -e "Enter :\n1. Display entire contents of the file\n2. Display student info by roll number\n3. Delete student entry by roll number\n4. Add a new student entry\n5. Update student entry\n6. Exit"
    read choice

    case $choice in
        1) display_file ;;
        2) display_student ;;
        3) delete_student ;;
        4) add_student ;;
        5) update_student ;;
        6) break ;;
        *) echo "Invalid choice." ;;
    esac
done
