Module PointsAndRectangles
  
  type point
     real :: x,y
  end type point
  real(8),parameter :: pi = 3.14159265359

  type rectangle
     type(point) :: lowerLeft, upperRight
  end type rectangle

contains
  real(4) function length(p)
    implicit none
    type(point),intent(in) :: p
    length = sqrt(p%x**2 + p%y**2 )
  end function length

  real(4) function angle(p)
    implicit none
    type(point),intent(in) :: p
    angle = atan(p%x,p%y)/pi
  end function angle

  real(4) function area(r)
    implicit none
    type(rectangle),intent(in) :: r
    area = (r%upperRight%x - r%lowerLeft%x) * (r%upperRight%y - r%lowerLeft%y)
  end function area
end Module PointsAndRectangles

Program hw10
  use PointsAndRectangles
  implicit none

  real(4) llx, lly, urx, ury
  type(point) :: ll, ur
  type(rectangle) :: rect

  read *,llx,lly
  read *,urx,ury

  print *, area(rectangle(point(llx,lly),point(urx,ury)))
end program hw10


