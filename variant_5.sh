#!/bin/bash

errors_count=0
operation_number=1

while [ $operation_number -ne 0 ]
do
    echo "1. Copy file"
    echo "2. Compress file"
    echo "3. Move compressed file to /home/arch/"
    echo "4. About program(help)"
    echo "0. Exit"

    read operation_number

    case "$operation_number" in
        "1" )
            # copy
            echo "Enter path to file:"
            read path_to_original_file
            echo "Enter path to directory for copying:"
            read path_to_directory

            ./copy $path_to_original_file $path_to_directory
            if [ $? -ne 0 ]; then
                echo "Copying failed"
                let "errors_count+=1"
            fi

        ;;

        "2" )
            # compress
            echo "Enter path to file:"
            read path_to_file

            ./compress $path_to_file
            if [ $? -ne 0 ]; then
                echo "Compressing failed"
                let "errors_count+=1"
            fi
        ;;

        "3" )
            echo "Enter path to file:"
            read path_to_file

            ./move $path_to_file
            if [ $? -ne 0 ]; then
                echo "Moving file failed"
                let "errors_count+=1"
            fi
        ;;

        "4" )
            # print help
            echo "shell script for lab 2" 
        ;;
    esac
done

echo "Errors count: $errors_count"
