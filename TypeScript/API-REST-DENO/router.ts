import { Router } from 'https://deno.land/x/oak/mod.ts'
import { getAllItems, getItem, addItem, deleteItem } from './items.ts'

const router = new Router()

router.get('/api/v1/getallitems', getAllItems)
    .get('/api/v1/getitem/:id', getItem)
    .post('/api/v1/additem', addItem)
    .delete('/api/v1/deleteitem/:id', deleteItem)

export default router