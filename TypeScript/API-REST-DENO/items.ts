import { v4 } from 'https://deno.land/std/uuid/mod.ts'
import { Item } from './interface.ts'

let items: Item[] = [
    {
        id: "1",
        name: "Product One",
        description: "This is my item 1",
        price: 29.99
    },
    {
        id: "2",
        name: "Product Two",
        description: "This is my item 2",
        price: 39.99
    },
    {
        id: "3",
        name: "Product Three",
        description: "This is my item 3",
        price: 49.99
    }
]

const getAllItems = ({ response }: { response: any }) => {
    response.body = {
        success: true,
        data: items
    }
}

const getItem = ({ params, response }: { params: { id: string }, response: any }) => {
    const item: Item | undefined = items.find(p => p.id === params.id)

    if (item) {
        response.status = 200
        response.body = {
            success: true,
            data: item
        }
    } else {
        response.status = 404
        response.body = {
            success: false,
            data: ""
        }
    }
}

const addItem = async ({ request, response }: { request: any, response: any }) => {
    const body = await request.body()

    if (!request.hasBody) {
        response.status = 400
        response.body = {
            success: false,
            msg: "No Data Found"
        }
    } else {
        const item: Item = body.value
        item.id = v4.generate()
        items.push(item)
        response.status = 201
        response.body = {
            success: true,
            data: item
        }
    }
}

const deleteItem = ({ params, response }: { params: { id: string }, response: any }) => {
    items = items.filter(p => p.id !== params.id)
    response.body = {
        success: true,
        msg: "Item Removed"
    }
}


export { getAllItems, getItem, addItem, deleteItem }