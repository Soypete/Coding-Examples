import turtle

def draw_square(some_turtle):
    for x in range(4):
        some_turtle.forward(100)
        some_turtle.right(90)
        
def draw_circle():
    window = turtle.Screen()
    window.bgcolor("red")
    
    henry = turtle.Turtle()
    henry.shape("turtle")
    henry.color("blue")
    henry.speed(3)
    for x in range(36):       
        draw_square(henry)
        henry.right(10)

    window.exitonclick()    

def draw_shapes():
    window = turtle.Screen()
    window.bgcolor("red")

    #square
    henry = turtle.Turtle()
    henry.shape("turtle")
    henry.color("blue")
    henry.speed(1)
    draw_square(henry)
    #circke
    ellie = turtle.Turtle()
    ellie.shape("arrow")
    ellie.color("green")
    ellie.circle(100)
    #triangle
    jake = turtle.Turtle()
    jake.shape("circle")
    jake.color("black")
    for x in range(3):
        jake.forward(100)
        jake.left(120)

    window.exitonclick()     
        
def draw_test():
    
    

#draw_shapes()

#draw_circle()

draw_test()    
