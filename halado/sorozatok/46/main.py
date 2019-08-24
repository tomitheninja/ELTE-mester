s = "  <ALMA>  <BARACK> CSERESZNYE </BARACK> <MEGGY> DINNYE </MEGGY> </ALMA>*"

get_next_char_i = -1
def get_next_char():
    global get_next_char_i
    get_next_char_i += 1
    return s[get_next_char_i]
def jump_to_last_char():
    global get_next_char_i
    get_next_char_i -= 1

# TODO: abstract parent

class TreeItem:
    def __init__(self, parent, is_container, c = None):
        self.parent = parent
        if (is_container):
            self.type = "container"
            self.children = []
            self.class_name = c
        else:
            self.type = "text"
            self.text = c

rootNode = TreeItem(None, True)
parent = rootNode
c = ' '

while True:
    c = get_next_char()
    if c == '*':
        break
    elif c == ' ' or c == '\t': # skip outer whitespace
        pass
    elif c == '<': # start of container definition
        is_closing_tag = False
        c = get_next_char()
        node_class_name = ""
        if c == '/':
            is_closing_tag = True
        else:
            node_class_name += c
        while not node_class_name.endswith('>'):
            c = get_next_char()
            node_class_name += c
        node_class_name = node_class_name[:-1] # remove the last char (>)
        if is_closing_tag:
            parent = parent.parent
        else:
            x = TreeItem(parent, True, node_class_name)
            parent.children.append(x)
            parent = x
    else: # start of text definition TODO!
        text = "" + c
        c = get_next_char()
        while c != '<' and c != '*':
            text += c
            c = get_next_char()
        text = text.strip()
        jump_to_last_char()
        x = TreeItem(parent, False, text)
        parent.children.append(x)


rootNode