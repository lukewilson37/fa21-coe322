Program LinkedList

  implicit none

  type node
     integer(8) :: value
     type(node),pointer :: next
  end type node

  type list
     type(node),pointer :: head
  end type list

  type(list) :: the_list
  !type(node),pointer :: node_ptr
  integer(8) :: n

  nullify(the_list%head)

  read *,n
  do while(n /= 0)
     call insert(the_list, n)
     call print(the_list)
     read *,n
  end do
  call print(the_list)

contains

  subroutine insert( the_list, new_value)
    implicit none
    !parameters
    type(list),intent(inout) :: the_list
    integer(8),intent(in) :: new_value
    !local
    type(node),pointer :: current,previous,new_node
    
    allocate(new_node); new_node%value = new_value 
    
    if(.not.associated(the_list%head)) then
       nullify(new_node%next)
       the_list%head => new_node
    else
       previous => the_list%head
       current => previous%next
       if (new_node%value < previous%value) then
          new_node%next => previous
          the_list%head => new_node
       else
       
          do while(associated(current))
             if (current%value > new_node%value) exit
             previous => current
             current => current%next
             if (.not.associated(current)) then
                nullify(current)
             end if
          end do
          new_node%next => current
          previous%next => new_node
       end if
    end if

  end subroutine insert

  integer function length(the_list)
    implicit none
    type(list),intent(in) :: the_list
    !local
    type(node),pointer :: current

    if(.not.associated(the_list%head)) then
       length = 0
    else
       current => the_list%head
       do
          length = length + 1
          if (.not.associated(current%next)) exit
          current => current%next
       end do
    end if
  end function length

  subroutine print(the_list)
    implicit none
    type(list),intent(in) :: the_list
    type(node),pointer :: current
    
    write(*,'("List: [ ")',advance="no")
    if (associated(the_list%head)) then
       current => the_list%head
       do while(associated(current))
          write(*,'(i3",")',advance="no") current%value
          if(.not.associated(current%next)) exit
          current => current%next
       end do
    end if
    write(*,'(x"]")')
    
  end subroutine print

end Program LinkedList
